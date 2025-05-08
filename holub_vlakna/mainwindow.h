#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "factorialtask.h"
#include "primetask.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_factorialStart_clicked();

    void on_factorialCancel_clicked();

    void on_primeStart_clicked();

    void on_primeCancel_clicked();

private:
    Ui::MainWindow *ui;

    FactorialTask *factorialTask = nullptr;
    bool factorialRunning = false;
    bool factorialPaused = false;

    PrimeTask *primeTask = nullptr;
    bool primeRunning = false;
    bool primePaused = false;


};
#endif // MAINWINDOW_H
