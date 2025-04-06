#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tracerouteCmd = new TracerouteCommand(ui->outprint, this);
    pingCmd = new PingCommand(ui->outprint, this);
    netstatCmd = new NetstatCommand(ui->outprint, this);

    connect(tracerouteCmd, &TracerouteCommand::runningChanged, this, [this](bool running) {
        ui->traceroute_start->setEnabled(!running);
        ui->traceroute_stop->setEnabled(running);
    });

    connect(pingCmd, &PingCommand::runningChanged, this, [this](bool running) {
        ui->ping_start->setEnabled(!running);
        ui->ping_stop->setEnabled(running);
    });

    connect(netstatCmd, &NetstatCommand::runningChanged, this, [this](bool running) {
        ui->netstat_start->setEnabled(!running);
        ui->netstat_stop->setEnabled(running);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_traceroute_start_clicked()
{
    if(isAnyCommandRunning()){
        return;
    }
    tracerouteCmd->setTarget(ui->traceroute_ip->text());
    tracerouteCmd->start();
}


void MainWindow::on_traceroute_stop_clicked()
{
    tracerouteCmd->stop();
}


void MainWindow::on_ping_start_clicked()
{
    if(isAnyCommandRunning()){
        return;
    }
    pingCmd->setTarget(ui->ping_ip->text());
    pingCmd->setCount(ui->ping_count->value());
    pingCmd->setInfinite(ui->ping_infinite->isChecked());
    pingCmd->start();
}


void MainWindow::on_ping_stop_clicked()
{
    pingCmd->stop();
}


void MainWindow::on_netstat_start_clicked()
{
    if(isAnyCommandRunning()){
        return;
    }
    netstatCmd->setA(ui->netstat_a->isChecked());
    netstatCmd->setN(ui->netstat_n->isChecked());
    netstatCmd->setO(ui->netstat_o->isChecked());
    netstatCmd->start();
}


void MainWindow::on_netstat_stop_clicked()
{
    netstatCmd->stop();
}

bool MainWindow::isAnyCommandRunning()
{
    bool isAnyRunning = tracerouteCmd->isRunning() || pingCmd->isRunning() || netstatCmd->isRunning();
    if(isAnyRunning){
        ui->outprint->append("<span style='color:red;'>Nelze spustit více příkazů současně.</span>");
    }
    return isAnyRunning;
}

