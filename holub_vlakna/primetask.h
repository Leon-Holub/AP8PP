#ifndef PRIMETASK_H
#define PRIMETASK_H

#include <QObject>
#include <QRunnable>
#include <QElapsedTimer>
#include <QMutex>
#include <QWaitCondition>
#include <atomic>
#include <qcolor.h>

/**
 * @class PrimeTask
 * @brief Třída provádějící výpočet prvočísel pomocí Eratosthenova síta.
 *
 * Běží jako vlákno pomocí QRunnable, podporuje pauzu a zrušení.
 */
class PrimeTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor.
     * @param max Horní mez pro hledání prvočísel.
     * @param parent Volitelný rodič QObject.
     */
    explicit PrimeTask(int max, QObject *parent = nullptr);

    void run() override;
    void cancel();
    void pause();
    void resume();

signals:
    void progressChanged(int percent);
    void etaChanged(const QString &eta);
    void finished();
    void canceled();

    /**
     * @brief Posílá textovou zprávu pro výpis do logu.
     * @param message Obsah zprávy.
     * @param color Barva zprávy.
     */
    void logMessage(const QString &message, QColor color = QColor("#27ae60"));

private:
    int upperLimit;
    std::atomic_bool m_cancelled{false};
    std::atomic_bool m_paused{false};
    QMutex m_mutex;
    QWaitCondition m_pauseCondition;

    void waitIfPaused();
};

#endif // PRIMETASK_H
