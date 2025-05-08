#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bubblesorttask.h"
#include "factorialtask.h"
#include "primetask.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Hlavní okno aplikace pro správu asynchronních výpočtů.
 *
 * Umožňuje spuštění, pozastavení a zrušení tří typů výpočtů (faktoriál, síto, bubble sort).
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor.
     * @param parent Rodičovský widget (defaultně nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /** @brief Destruktor. */
    ~MainWindow();

private slots:
    /** @brief Obsluha tlačítka Start pro výpočet faktoriálu. */
    void on_factorialStart_clicked();

    /** @brief Obsluha tlačítka Cancel pro faktoriál. */
    void on_factorialCancel_clicked();

    /** @brief Obsluha tlačítka Start pro Eratosthenovo síto. */
    void on_primeStart_clicked();

    /** @brief Obsluha tlačítka Cancel pro síto. */
    void on_primeCancel_clicked();

    /** @brief Obsluha tlačítka Start pro bubble sort. */
    void on_bubbleSortStart_clicked();

    /** @brief Obsluha tlačítka Cancel pro bubble sort. */
    void on_bubbleSortCancel_clicked();

    /**
     * @brief Zobrazí zprávu do výstupního logu s barevným zvýrazněním.
     * @param msg Zpráva.
     * @param color Barva textu.
     */
    void logMessage(const QString &msg, const QColor &color = Qt::black);

private:
    Ui::MainWindow *ui;

    FactorialTask *factorialTask = nullptr;
    bool factorialRunning = false;
    bool factorialPaused = false;

    PrimeTask *primeTask = nullptr;
    bool primeRunning = false;
    bool primePaused = false;

    BubbleSortTask *bubbleTask = nullptr;
    bool bubbleRunning = false;
    bool bubblePaused = false;
};
#endif // MAINWINDOW_H
