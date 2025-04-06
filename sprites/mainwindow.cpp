#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>

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

void MainWindow::on_actionAdd_sprite_triggered()
{
    sprites.append(std::make_shared<Sprite>(this));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::lightGray);

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::white));

    for(auto sprite: sprites){
        sprite->draw(painter);
    }
}


void MainWindow::on_actionRemove_last_triggered()
{
    if(!sprites.empty()){
        sprites.removeLast();
        update();
    }
}


void MainWindow::on_actionRemove_all_triggered()
{
    sprites.clear();
    update();
}

