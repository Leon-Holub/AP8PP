#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(&idleTimer, &QTimer::timeout, this, &MainWindow::on_time_up);
    ui->setupUi(this);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->NumberTextField->setText(QString::number(numberToCount));
    setProgressBarValue(0);
    setButtonsText();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Sets the application state and updates button texts
 * @param newState The new state of the application
 */
void MainWindow::setState(State newState)
{
    state = newState;
    setButtonsText();
}

/**
 * @brief Sets the progress bar value
 * @param value New progress bar value in percentage
 */
void MainWindow::setProgressBarValue(int value)
{
    ui->progressBar->setValue(value);
}

/**
 * @brief Iterative step for primality testing
 */
void MainWindow::isPrimeStep()
{
    if (!isPrimeInProgress) return;

    int iterations = 0;
    while (currentDivisor <= maxDivisor && iterations < 100) {
        if (numberToCount % currentDivisor == 0) {
            qDebug() << "Číslo NENÍ prvočíslo! Dělitel: " << currentDivisor;
            isPrimeInProgress = false;
            idleTimer.stop();
            setProgressBarValue(100);
            setState(State::STOPED);
            ui->ResultText->setText("Číslo NENÍ prvočíslo! Dělitel: " + QString::number(currentDivisor));
            return;
        }
        currentDivisor++;
        iterations++;
    }

    int progress = 0;
    if (maxDivisor > 2) {
        progress = ((currentDivisor - 2) * 100) / (maxDivisor - 2);
    }
    setProgressBarValue(progress);


    if (currentDivisor > maxDivisor) {
        qDebug() << "Číslo JE prvočíslo!";
        isPrimeInProgress = false;
        idleTimer.stop();
        setProgressBarValue(100);
        setState(State::STOPED);
        ui->ResultText->setText("Číslo JE prvočíslo!");
    }
}

/**
 * @brief Updates button texts based on the current application state
 */
void MainWindow::setButtonsText()
{
    switch (state) {
    case State::RUNNING:
        ui->PauseButton->setText("Pause");
        ui->startButton->setText("Stop");
        ui->PauseButton->setDisabled(false);
        ui->NumberTextField->setDisabled(true);
        ui->StateText->setText("");
        ui->ResultText->setText("");
        break;
    case State::PAUSED:
        ui->PauseButton->setText("Resume");
        ui->StateText->setText("!!! PAUSED !!!");
        break;
    case State::STOPED:
        ui->PauseButton->setText("Pause");
        ui->PauseButton->setDisabled(true);
        ui->startButton->setText("Start");
        ui->StateText->setText("");
        ui->NumberTextField->setDisabled(false);
    default:
        break;
    }
}

/**
 * @brief Starts the primality test
 */
void MainWindow::startAction()
{
    bool ok;
    setNumberToCount(&ok);
    if(!ok){
        ui->ResultText->setText("Zadaný text neodpovídá požadavkům pro číslo");
        return;
    }
    maxDivisor = qSqrt(numberToCount);
    currentDivisor = 2;
    setState(State::RUNNING);
    isPrimeInProgress = true;
    idleTimer.start(0);
}

/**
 * @brief Stops the primality test
 */
void MainWindow::stopAction()
{
    setState(State::STOPED);
    idleTimer.stop();
    isPrimeInProgress = false;
}


/**
 * @brief Pauses the primality test
 */
void MainWindow::pauseAction()
{
    idleTimer.stop();
    isPrimeInProgress = false;
    setState(State::PAUSED);
}


/**
 * @brief Resumes the primality test after a pause
 */
void MainWindow::resumeAction()
{
    setState(State::RUNNING);
    isPrimeInProgress = true;
    idleTimer.start(0);
}

/**
 * @brief Sets the number for primality testing based on user input
 * @param ok Pointer to a bool to confirm successful conversion
 */
void MainWindow::setNumberToCount(bool *ok)
{
    unsigned long long numberToCount = ui->NumberTextField->text().toULongLong(ok);

    if (!*ok) {
        qDebug() << "Neplatné číslo!";
    } else {
        this->numberToCount = numberToCount;
    }
}

/**
 * @brief Action called when time is up.
 */
void MainWindow::on_time_up()
{
    if(!idleTimer.isActive())
        return;

    isPrimeStep();
}

/**
 * @brief on Pause/Resume button clicked
 */
void MainWindow::on_PauseButton_clicked()
{
    if(idleTimer.isActive()){
        pauseAction();
    }else {
        resumeAction();
    }
}


/**
 * @brief on Start/Stop button clicked
 */
void MainWindow::on_startButton_clicked()
{
    if(state == State::STOPED){
        startAction();
    } else {
        stopAction();
    }
}
