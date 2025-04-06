#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "netstatcommand.h"
#include "pingcommand.h"
#include "traceroutecommand.h"

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
    void on_traceroute_start_clicked();

    void on_traceroute_stop_clicked();

    void on_ping_start_clicked();

    void on_ping_stop_clicked();

    void on_netstat_start_clicked();

    void on_netstat_stop_clicked();

    bool isAnyCommandRunning();

private:
    Ui::MainWindow *ui;
    TracerouteCommand *tracerouteCmd;
    PingCommand *pingCmd;
    NetstatCommand *netstatCmd;
};
#endif // MAINWINDOW_H
