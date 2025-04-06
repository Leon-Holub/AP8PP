#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateUI(false);

    connect(&echo, &QProcess::stateChanged, this, &MainWindow::onEchoStateChanged);
    connect(&echo, &QProcess::errorOccurred, this, &MainWindow::onEchoErrorOccured);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUI(bool enabled)
{
    ui->lineEdit->setEnabled(enabled);
    ui->textEdit->setEnabled(enabled);
}

void MainWindow::on_pushButton_clicked()
{
    switch(echo.state()){
    case QProcess::NotRunning:
        echo.setWorkingDirectory(QCoreApplication::applicationDirPath());
        echo.start("Echo.exe");
        break;
    case QProcess::Starting:
    case QProcess::Running:
        // echo.terminate()  musí mít implementovanou smyčku událostí
        echo.close();
        // echo.kill()
        break;
    }
}

void MainWindow::onEchoStateChanged(QProcess::ProcessState state)
{
    switch (state) {
    case QProcess::NotRunning:
        updateUI(false);
        ui->pushButton->setText("Start echo process");
        break;
    case QProcess::Starting:
    case QProcess::Running:
        updateUI(true);
        ui->pushButton->setText("Close echo process");
        break;
    default:
        break;
    }
}

void MainWindow::onEchoErrorOccured(QProcess::ProcessError error)
{
    if(ui->actionTrack_Errorrs->isChecked()){
        QMessageBox::critical(this, "EchoGUI", tr("Error %1 occured").arg(error));
    }
}

