#ifndef BUBBLESORTTASK_H
#define BUBBLESORTTASK_H

#include <QObject>
#include <QRunnable>
#include <QElapsedTimer>
#include <QMutex>
#include <QWaitCondition>
#include <atomic>
#include <qcolor.h>

/**
 * @class BubbleSortTask
 * @brief Třída provádějící řazení pomocí bubble sortu v samostatném vlákně.
 *
 * Umožňuje pozastavení, zrušení a sleduje průběh výpočtu.
 */
class BubbleSortTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor.
     * @param size Počet prvků pole, které se má seřadit.
     * @param parent Volitelný rodič QObject.
     */
    explicit BubbleSortTask(int size, QObject *parent = nullptr);

    /** @brief Spustí řazení. */
    void run() override;

    /** @brief Zruší výpočet. */
    void cancel();

    /** @brief Pozastaví výpočet. */
    void pause();

    /** @brief Pokračuje ve výpočtu. */
    void resume();

signals:
    /** @brief Signalizuje změnu postupu výpočtu v procentech. */
    void progressChanged(int percent);

    /** @brief Signalizuje odhadovaný zbývající čas. */
    void etaChanged(const QString &eta);

    /** @brief Signalizuje dokončení výpočtu. */
    void finished();

    /** @brief Signalizuje zrušení výpočtu. */
    void canceled();

    /**
     * @brief Posílá textovou zprávu pro výpis do logu.
     * @param message Obsah zprávy.
     * @param color Barva zprávy.
     */
    void logMessage(const QString &message, QColor color = QColor("#8e44ad"));

private:
    int dataSize;
    std::atomic_bool m_cancelled{false};
    std::atomic_bool m_paused{false};

    QMutex m_mutex;
    QWaitCondition m_pauseCondition;

    /** @brief Čeká, pokud je výpočet pozastaven. */
    void waitIfPaused();
};

#endif // BUBBLESORTTASK_H
