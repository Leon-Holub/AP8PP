#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ball.h"
#include "paddle.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Hlavní okno aplikace - spravuje vykreslování, kuličky a paddle.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;

protected:
    /**
     * @brief Překreslovací událost.
     * @param event Ukazatel na událost překreslení.
     */
    virtual void paintEvent(QPaintEvent *event) override;

    /**
     * @brief Klávesová událost.
     * @param event Ukazatel na událost stisknutí klávesy.
     */
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    QList<Ball*> balls;
    Paddle *paddle;
    int score = 0;
    float ballInterval = 1000;
    bool shouldReduceTimer = false;

    /**
     * @brief Kontrola kolizí mezi kuličkami a paddle.
     */
    void checkCollisions();

    /**
     * @brief Nastaví nový interval generování kuliček.
     */
    void restartTimer();

    /**
     * @brief Restartuje časovač s aktuálním intervalem.
     */
    void setNewInterval();

private slots:
    /**
     * @brief Vytvoří novou kuličku a přidá ji do hry.
     */
    void createNewBall();

    /**
     * @brief Odstraní kuličku ze seznamu a uvolní její paměť.
     * @param ball Ukazatel na kuličku k odstranění.
     */
    void removeBall(Ball* ball);
};
#endif // MAINWINDOW_H
