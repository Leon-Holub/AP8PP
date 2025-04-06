#ifndef BALL_H
#define BALL_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include <QObject>

/**
 * @class Ball
 * @brief Reprezentuje pohybující se kuličku ve hře.
 */
class Ball : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor Ball.
     * @param parent Ukazatel na rodičovský widget.
     */
    explicit Ball(QWidget *parent = nullptr);

    /**
     * @brief Vykreslí kuličku.
     * @param painter Odkaz na QPainter pro vykreslení.
     */
    void draw(QPainter &painter);

    /**
     * @brief Vrací X-ovou souřadnici kuličky.
     * @return Souřadnice X.
     */
    float getX();

    /**
     * @brief Vrací Y-ovou souřadnici kuličky.
     * @return Souřadnice Y.
     */
    float getY();

    /**
     * @brief Vrací vertikální rychlost kuličky.
     * @return Rychlost v ose Y.
     */
    float getKY();

private slots:
    /**
     * @brief Aktualizuje pozici kuličky.
     */
    void updatePosition();

signals:
    /**
     * @brief Signál pro zničení kuličky.
     * @param ball Ukazatel na tuto kuličku.
     */
    void destroyBall(Ball*);

private:
    QWidget *m_parent;
    QTimer *timer;

    int m_x;
    int m_y;
    float m_kx;
    float m_ky;

    float gravity = 0.1;
    float maxSpeed = 10.0;
};

#endif // BALL_H
