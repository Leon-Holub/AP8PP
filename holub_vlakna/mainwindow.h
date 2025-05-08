#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bubblesorttask.h"
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

    void on_bubbleSortStart_clicked();

    void on_bubbleSortCancel_clicked();

    void logMessage(const QString &msg);

private:
    Ui::MainWindow *ui;

    FactorialTask *factorialTask = nullptr;
    bool factorialRunning = false;
    bool factorialPaused = false;

    PrimeTask *primeTask = nullptr;
    bool primeRunning = false;
    bool primePaused = false;

    BubbleSortTask *bubbleTask = nullptr;
    bool bubbleRunning = false;
    bool bubblePaused = false;


};
#endif // MAINWINDOW_H
