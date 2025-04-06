#include "sprite.h"


Sprite::Sprite(QWidget *parent):m_parent{parent}{
    QRect rct = parent->rect();
    m_x = rand() % rct.width();
    m_y = rand() % rct.height();

    m_kx = rand() % 10;
    m_ky = rand() %10;
    start(10);
}

void Sprite::draw(QPainter &painter)
{
    painter.drawEllipse(m_x, m_y, 15, 15);
}

void Sprite::timerEvent(QTimerEvent *)
{
    QRect rct = m_parent->rect();

    if(m_x > rct.width() || m_x < 0){
        m_kx *= -1;
    }

    if(m_y > rct.height() || m_y < 0){
        m_ky *= -1;
    }

    m_x += m_kx;
    m_y += m_ky;

    m_parent->update();
}
