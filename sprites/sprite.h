#ifndef SPRITE_H
#define SPRITE_H

#include <QTimer>
#include <QWidget>
#include <QPainter>

class Sprite : public QTimer
{
public:
    explicit Sprite(QWidget * parent);
    void draw(QPainter &painter);

protected:
    virtual void timerEvent(QTimerEvent *) override;

private:
    QWidget *m_parent;
    int m_x;
    int m_y;
    float m_kx;
    float m_ky;
};

#endif // SPRITE_H
