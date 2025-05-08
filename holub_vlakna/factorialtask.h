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

class FactorialTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit FactorialTask(quint64 n, QObject *parent = nullptr);
    void run() override;

    void cancel();
    void pause();
    void resume();

signals:
    void progressChanged(int percent);
    void etaChanged(const QString &eta);
    void finished();
    void canceled();
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
