#include "paddle.h"

Paddle::Paddle(QWidget *parent) : QWidget(parent)
{
    x = parent->width() / 2 - width / 2;  // Výchozí pozice uprostřed
}

void Paddle::draw(QPainter &painter)
{
    painter.setBrush(Qt::blue);
    painter.drawRect(x, parentWidget()->height() - 50, width, height);
}

void Paddle::moveLeft()
{
    x -= speed;
    if (x < 0) x = 0;
    update();
}

void Paddle::moveRight()
{
    int screenWidth = parentWidget()->width();
    x += speed;
    if (x + width > screenWidth) x = screenWidth - width;
    update();
}

void Paddle::setPosition(int newX)
{
    int screenWidth = parentWidget()->width();
    x = newX - width / 2;
    if (x < 0) x = 0;
    if (x + width > screenWidth) x = screenWidth - width;
    update();
}

QRect Paddle::getRect() const
{
    return QRect(x, parentWidget()->height() - 50, width, height);
}
