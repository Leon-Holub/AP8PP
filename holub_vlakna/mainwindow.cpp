#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QThreadPool>
#include <QTime>

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
            factorialRunning = false;
            ui->factorialStart->setText("Start");
            ui->factorialETA->setText("Hotovo");
        });
        connect(factorialTask, &FactorialTask::canceled, this, [=]() {
            factorialRunning = false;
            ui->factorialStart->setText("Start");
        });

        connect(factorialTask, &FactorialTask::logMessage, this, &MainWindow::logMessage);

        QThreadPool::globalInstance()->start(factorialTask);
        factorialRunning = true;
        factorialPaused = false;
        ui->factorialStart->setText("Pozastavit");

    } else if (!factorialPaused) {
        factorialTask->pause();
        factorialPaused = true;
        logMessage("Faktoriál pozastaven.");
        ui->factorialStart->setText("Pokračovat");

    } else {
        factorialTask->resume();
        factorialPaused = false;
        logMessage("Faktoriál pokračuje.");
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
            logMessage("Prvočísla: " + result);
            primeRunning = false;
            ui->primeStart->setText("Start");
            ui->primeETA->setText("Hotovo");
        });
        connect(primeTask, &PrimeTask::canceled, this, [=]() {
            primeRunning = false;
            ui->primeStart->setText("Start");
        });
        connect(primeTask, &PrimeTask::logMessage, this, &MainWindow::logMessage);

        QThreadPool::globalInstance()->start(primeTask);
        primeRunning = true;
        primePaused = false;
        ui->primeStart->setText("Pozastavit");

    } else if (!primePaused) {
        primeTask->pause();
        primePaused = true;
        logMessage("Výpočet prvočísel pozastaven.");
        ui->primeStart->setText("Pokračovat");

    } else {
        primeTask->resume();
        primePaused = false;
        logMessage("Výpočet prvočísel pokračuje.");
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


void MainWindow::on_bubbleSortStart_clicked()
{
    if (!bubbleRunning) {
        bool ok = false;
        int size = ui->bubbleSortValue->text().toInt(&ok);
        if (!ok || size < 2) {
            ui->outputText->append("Zadej velikost pole větší než 1 pro Bubble Sort.");
            return;
        }

        ui->bubbleSortProgressBar->setValue(0);
        ui->bubbleSortETA->setText("počítám...");

        bubbleTask = new BubbleSortTask(size);

        connect(bubbleTask, &BubbleSortTask::progressChanged, ui->bubbleSortProgressBar, &QProgressBar::setValue);
        connect(bubbleTask, &BubbleSortTask::etaChanged, ui->bubbleSortETA, &QLabel::setText);
        connect(bubbleTask, &BubbleSortTask::finished, this, [=](const QString &result) {
            logMessage("Bubble Sort výsledek: " + result);
            bubbleRunning = false;
            ui->bubbleSortStart->setText("Start");
            ui->bubbleSortETA->setText("Hotovo");
        });
        connect(bubbleTask, &BubbleSortTask::canceled, this, [=]() {
            bubbleRunning = false;
            ui->bubbleSortStart->setText("Start");
        });
        connect(bubbleTask, &BubbleSortTask::logMessage, this, &MainWindow::logMessage);

        QThreadPool::globalInstance()->start(bubbleTask);
        bubbleRunning = true;
        bubblePaused = false;
        ui->bubbleSortStart->setText("Pozastavit");

    } else if (!bubblePaused) {
        bubbleTask->pause();
        bubblePaused = true;
        logMessage("Bubble Sort pozastaven.");
        ui->bubbleSortStart->setText("Pokračovat");

    } else {
        bubbleTask->resume();
        bubblePaused = false;
        logMessage("Bubble Sort pokračuje.");
        ui->bubbleSortStart->setText("Pozastavit");
    }
}


void MainWindow::on_bubbleSortCancel_clicked()
{
    if (bubbleTask && bubbleRunning) {
        bubbleTask->cancel();
        bubblePaused = false;
        ui->bubbleSortStart->setText("Start");
    }
}

void MainWindow::logMessage(const QString &msg)
{
    QString time = QTime::currentTime().toString("HH:mm:ss");
    ui->outputText->append(QString("[%1] %2").arg(time, msg));
}

