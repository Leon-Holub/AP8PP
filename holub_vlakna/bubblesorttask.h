#ifndef BUBBLESORTTASK_H
#define BUBBLESORTTASK_H

#include <QObject>
#include <QRunnable>
#include <QElapsedTimer>
#include <QMutex>
#include <QWaitCondition>
#include <atomic>
#include <qcolor.h>

class BubbleSortTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSortTask(int size, QObject *parent = nullptr);
    void run() override;

    void cancel();
    void pause();
    void resume();

signals:
    void progressChanged(int percent);
    void etaChanged(const QString &eta);
    void finished();
    void canceled();
    void logMessage(const QString &message, QColor color = QColor("#8e44ad"));

private:
    int dataSize;
    std::atomic_bool m_cancelled{false};
    std::atomic_bool m_paused{false};

    QMutex m_mutex;
    QWaitCondition m_pauseCondition;

    void waitIfPaused();
};

#endif // BUBBLESORTTASK_H
