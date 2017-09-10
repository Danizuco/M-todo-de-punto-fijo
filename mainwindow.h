#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double funcion(double c);  //Are you a name to the function that returns the function used in this program
private:
    Ui::MainWindow *ui;

public slots:
    void metodo(); //Slot that carries out the numerical method of fixed point
    void borrar(); //Slot that erases the contents of the spinbox and text

};

#endif // MAINWINDOW_H
