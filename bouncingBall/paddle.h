#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include <QPainter>

/**
 * @class Paddle
 * @brief Paddle, který hráč ovládá pro odrážení kuliček.
 */
class Paddle : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor Paddle.
     * @param parent Rodičovský widget.
     */
    explicit Paddle(QWidget *parent = nullptr);

    /**
     * @brief Vykreslí paddle.
     * @param painter Odkaz na QPainter.
     */
    void draw(QPainter &painter);

    /**
     * @brief Pohyb vlevo.
     */
    void moveLeft();

    /**
     * @brief Pohyb vpravo.
     */
    void moveRight();

    /**
     * @brief Nastaví X-ovou pozici paddle.
     * @param x Nová pozice.
     */
    void setPosition(int x);

    /**
     * @brief Vrací obdélník paddle pro kolize.
     * @return QRect paddle.
     */
    QRect getRect() const;

private:
    int x;
    const int width = 100;
    const int height = 15;
    const int speed = 50;
};

#endif // PADDLE_H
