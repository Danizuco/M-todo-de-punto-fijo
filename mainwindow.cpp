#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>               //Library for the use of text strings
#include <cmath>                 //Library for the use of mathematical functions

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{                                   //Connections of the slots
    ui->setupUi(this);
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::funcion(double c){   //The function is called
    return (exp(-c));                  //You write the function to use and returns the function
}

void MainWindow::metodo(){
    QString temp,temp2,temp3,temp4;      //Temporary use text strings
    double x1=ui->X1->value();           //Retrieves the value of X 1 of the spinbox
    double err=ui->Err->value();         //Retrieves the value of the error of the spinbox
    double xr=0.0;                       //The value of the root in zero starts
    double ea=100.0;                     //set the maximum error value that can be entered
    double ni=0;                         // Start the number of interactions at zero
    double no=0;                         // Start counter to zero
    while(ea>err){
        xr=funcion (x1);                 //It calculates the fixed point
        ea=100*std::abs(xr-x1)/xr;       //The error is calculated
        x1=xr;                           //Equal variables
        no=ni+1;                         //Increases the counter depending on the number of necessary interactions
        ni=no;                           //It equals the number of interactions with the counter

    }
    temp.append("Raiz=").append(temp2.setNum(xr)).append("\nError=").append(temp3.setNum(ea)).append("\nInteraciones=").append(temp4.setNum(ni));  //Se prepara el texto para ser presentado
    ui->Texto->setText(temp);            //The text is presented
}

void MainWindow::borrar(){
    ui->X1->setValue(0.0);               //The spinbox is deleted
     ui->Err->setValue(0.0);
    ui->Texto->clear();                  //Clears the text
}
