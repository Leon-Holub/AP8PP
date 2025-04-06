#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->speedLabel->setText("Interval: " + QString::number(ballInterval, 'f', 2));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::createNewBall);
    timer->start(ballInterval);

    paddle = new Paddle(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QMainWindow::paintEvent(event);

    painter.setBrush(QBrush(Qt::yellow));
    paddle->draw(painter);

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::red));

    for(auto ball: balls){
        ball->draw(painter);
    }

    checkCollisions();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        paddle->moveLeft();
    }
    else if (event->key() == Qt::Key_Right) {
        paddle->moveRight();
    }
    update();
}

void MainWindow::checkCollisions()
{
    QRect paddleRect = paddle->getRect();

    for (int i = balls.size() - 1; i >= 0; --i) {
        Ball *ball = balls[i];
        if(ball->getKY() <= 0 ) continue;

        QRect ballRect(ball->getX(), ball->getY(), 15, 15);

        if (paddleRect.intersects(ballRect)) {
            score++;
            ui->scoreCounter->display(score);
            removeBall(ball);
            setNewInterval();
        }
    }
}

void MainWindow::restartTimer()
{
    timer->setInterval(ballInterval);
}

void MainWindow::setNewInterval()
{
    shouldReduceTimer = true;
    if(ballInterval > 100)
        ballInterval *= 0.95;
    else
        ballInterval = 100;

    ui->speedLabel->setText("Interval: " + QString::number(ballInterval, 'f', 2));
}


void MainWindow::createNewBall()
{
    if(shouldReduceTimer){
        restartTimer();
        shouldReduceTimer = false;
    }

    Ball *ball = new Ball(this);
    balls.append(ball);
    connect(ball, &Ball::destroyBall, this, &MainWindow::removeBall);
}

void MainWindow::removeBall(Ball *ball)
{
    balls.removeOne(ball);
    delete ball;
    update();
}

