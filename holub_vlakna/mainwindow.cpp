#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QThreadPool>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_factorialStart_clicked()
{
    if (!factorialRunning) {
        // Spuštění nového výpočtu
        bool ok = false;
        quint64 n = ui->factorialValue->text().toULongLong(&ok);
        if (!ok) {
            ui->outputText->append("Zadej platné celé číslo pro faktoriál.");
            return;
        }

        factorialTask = new FactorialTask(n);

        connect(factorialTask, &FactorialTask::progressChanged, ui->factorialProgressBar, &QProgressBar::setValue);
        connect(factorialTask, &FactorialTask::etaChanged, ui->factorialETA, &QLabel::setText);
        connect(factorialTask, &FactorialTask::finished, this, [=](const QString &result) {
            ui->outputText->append("Faktoriál dokončen: " + result);
            factorialRunning = false;
            ui->factorialStart->setText("Start");
        });
        connect(factorialTask, &FactorialTask::canceled, this, [=]() {
            ui->outputText->append("Faktoriál zrušen.");
            factorialRunning = false;
            ui->factorialStart->setText("Start");
        });
        connect(factorialTask, &FactorialTask::logMessage, ui->outputText, &QTextEdit::append);

        QThreadPool::globalInstance()->start(factorialTask);
        factorialRunning = true;
        factorialPaused = false;
        ui->factorialStart->setText("Pozastavit");

    } else if (!factorialPaused) {
        factorialTask->pause();
        factorialPaused = true;
        ui->outputText->append("Faktoriál pozastaven.");
        ui->factorialStart->setText("Pokračovat");

    } else {
        factorialTask->resume();
        factorialPaused = false;
        ui->outputText->append("Faktoriál pokračuje.");
        ui->factorialStart->setText("Pozastavit");
    }
}


void MainWindow::on_factorialCancel_clicked()
{
    if (factorialTask && factorialRunning) {
        factorialTask->cancel();
        factorialPaused = false;
        ui->factorialStart->setText("Start");
    }
}

