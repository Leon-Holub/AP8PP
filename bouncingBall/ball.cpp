#include "ball.h"



Ball::Ball(QWidget *parent): m_parent(parent)
{
    QRect rct = parent->rect();
    m_x = rand() % rct.width();
    m_y = rct.height() - (rand() % (rct.height() / 10));

    m_kx = (rand() % 11 - 5);
    m_ky = -maxSpeed + (rand() % 10) / 10.0 - 0.5;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Ball::updatePosition);
    timer->start(10);
}

void Ball::draw(QPainter &painter)
{
    painter.drawEllipse(m_x, m_y, 15, 15);
}

float Ball::getX()
{
    return m_x;
}

float Ball::getY()
{
    return m_y;
}

float Ball::getKY()
{
    return m_ky;
}

void Ball::updatePosition()
{
    QRect rct = m_parent->rect();

    m_ky += gravity;

    if (m_ky > maxSpeed) {
        m_ky = maxSpeed;
    }

    if (m_x <= 0 || m_x >= rct.width() - 15) {
        m_kx *= -1;
    }

    if (m_y >= rct.height() - 15) {
        emit destroyBall(this);
        return;
    }

    m_x += m_kx;
    m_y += m_ky;

    m_parent->update();
}
