#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "State.cpp"

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
    void setState(State newState);
    void setProgressBarValue(int value);
    bool extracted();
    void isPrimeStep();
    void setButtonsText();
    void startAction();
    void stopAction();
    void pauseAction();
    void resumeAction();
    void setNumberToCount(bool *ok);

private slots:
    void on_time_up();

    void on_PauseButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer idleTimer;
    long counter = 0;
    unsigned long long numberToCount = 18446744073709551557ULL;
    unsigned long long currentDivisor = 2;
    unsigned long long maxDivisor = 0;
    bool isPrimeInProgress = false;
    State state = State::STOPED;
};
#endif // MAINWINDOW_H
