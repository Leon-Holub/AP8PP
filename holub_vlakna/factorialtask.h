#ifndef FACTORIALTASK_H
#define FACTORIALTASK_H

#include <QObject>
#include <QRunnable>
#include <QElapsedTimer>
#include <QMutex>
#include <QWaitCondition>
#include <atomic>
#include <cmath>
#include <QColor>

/**
 * @class FactorialTask
 * @brief Třída pro výpočet faktoriálu ve vlákně.
 *
 * Výpočet je simulovaný pomocí logaritmického součtu pro získání počtu číslic výsledku.
 */
class FactorialTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor.
     * @param n Číslo, jehož faktoriál se má vypočítat.
     * @param parent Volitelný rodič QObject.
     */
    explicit FactorialTask(quint64 n, QObject *parent = nullptr);

    /** @brief Spustí výpočet. */
    void run() override;

    /** @brief Zruší výpočet. */
    void cancel();

    /** @brief Pozastaví výpočet. */
    void pause();

    /** @brief Pokračuje ve výpočtu. */
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
    void logMessage(const QString &message, QColor color = QColor("#e67e22"));

private:
    quint64 number;
    std::atomic_bool m_cancelled{false};
    std::atomic_bool m_paused{false};
    QMutex m_mutex;
    QWaitCondition m_pauseCondition;

    void waitIfPaused();
};
#endif // FACTORIALTASK_H
