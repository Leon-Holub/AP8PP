#include "factorialtask.h"
#include <QThread>
#include <QDateTime>


FactorialTask::FactorialTask(quint64 n, QObject *parent)
    : QObject{parent}, number(n)
{
    setAutoDelete(true);
}

void FactorialTask::run()
{
    QElapsedTimer timer;
    timer.start();

    emit logMessage(QString("Spouštím výpočet faktoriálu %1")
                        .arg(QString::number(number)));

    double logSum = 0.0;
    for (quint64 i = 1; i <= number; ++i) {
        waitIfPaused();
        if (m_cancelled.load()) {
            emit canceled();
            emit logMessage("Výpočet faktoriálu byl zrušen.");
            return;
        }

        logSum += std::log10(i);

        if (i % (number / 100 + 1) == 0 || i == number) {
            int progress = int(100.0 * i / number);
            emit progressChanged(progress);

            qint64 elapsed = timer.elapsed();
            qint64 estimatedTotal = (elapsed * number) / i;
            qint64 remaining = estimatedTotal - elapsed;
            emit etaChanged(QTime(0, 0).addMSecs(remaining).toString("mm:ss"));
        }
    }

    int digits = static_cast<int>(std::floor(logSum)) + 1;
    emit finished();
    emit logMessage(QString("Počet číslic ve %1! je přibližně: %2").arg(number).arg(digits));
    emit logMessage("Výpočet faktoriálu dokončen.");

}

void FactorialTask::cancel()
{
    m_cancelled.store(true);
    resume();
}

void FactorialTask::pause()
{
    m_paused.store(true);
    emit logMessage("Faktoriál pozastaven.");
}

void FactorialTask::resume()
{
    m_paused.store(false);
    m_pauseCondition.wakeAll();
    emit logMessage("Faktoriál pokračuje.");
}

void FactorialTask::waitIfPaused()
{
    m_mutex.lock();
    while (m_paused.load() && !m_cancelled.load()) {
        m_pauseCondition.wait(&m_mutex);
    }
    m_mutex.unlock();
}
