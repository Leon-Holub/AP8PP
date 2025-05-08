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

        ui->factorialProgressBar->setValue(0);
        ui->factorialETA->setText("počítám odhad ...");

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


void MainWindow::on_primeStart_clicked()
{
    if (!primeRunning) {
        bool ok = false;
        int max = ui->primeValue->text().toInt(&ok);
        if (!ok || max < 2) {
            ui->outputText->append("Zadej platné číslo větší než 1 pro prvočísla.");
            return;
        }

        primeTask = new PrimeTask(max);

        ui->primeProgressBar->setValue(0);
        ui->primeETA->setText("počítám odhad ...");

        connect(primeTask, &PrimeTask::progressChanged, ui->primeProgressBar, &QProgressBar::setValue);
        connect(primeTask, &PrimeTask::etaChanged, ui->primeETA, &QLabel::setText);
        connect(primeTask, &PrimeTask::finished, this, [=](const QString &result) {
            ui->outputText->append("Prvočísla: " + result);
            primeRunning = false;
            ui->primeStart->setText("Start");
        });
        connect(primeTask, &PrimeTask::canceled, this, [=]() {
            ui->outputText->append("Výpočet prvočísel zrušen.");
            primeRunning = false;
            ui->primeStart->setText("Start");
        });
        connect(primeTask, &PrimeTask::logMessage, ui->outputText, &QTextEdit::append);

        QThreadPool::globalInstance()->start(primeTask);
        primeRunning = true;
        primePaused = false;
        ui->primeStart->setText("Pozastavit");

    } else if (!primePaused) {
        primeTask->pause();
        primePaused = true;
        ui->outputText->append("Výpočet prvočísel pozastaven.");
        ui->primeStart->setText("Pokračovat");

    } else {
        primeTask->resume();
        primePaused = false;
        ui->outputText->append("Výpočet prvočísel pokračuje.");
        ui->primeStart->setText("Pozastavit");
    }
}


void MainWindow::on_primeCancel_clicked()
{
    if (primeTask && primeRunning) {
        primeTask->cancel();
        primePaused = false;
        ui->primeStart->setText("Start");
    }
}

