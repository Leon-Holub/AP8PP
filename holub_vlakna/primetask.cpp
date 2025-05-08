#include "primetask.h"
#include <QDateTime>
#include <QThread>
#include <vector>
#include <cmath>

PrimeTask::PrimeTask(int max, QObject *parent)
    : QObject{parent}, upperLimit{max}
{}


void PrimeTask::run()
{
    QElapsedTimer timer;
    timer.start();

    emit logMessage(QString("Spouštím výpočet prvočísel do %1")
                        .arg(QString::number(upperLimit)));

    std::vector<bool> isPrime(upperLimit + 1, true);
    isPrime[0] = isPrime[1] = false;

    int processed = 0;
    int sqrtLimit = static_cast<int>(std::sqrt(upperLimit));

    for (int i = 2; i <= sqrtLimit; ++i) {
        waitIfPaused();

        if (m_cancelled.load()) {
            emit canceled();
            emit logMessage("Výpočet prvočísel byl zrušen.");
            return;
        }

        if (isPrime[i]) {
            for (int j = i * i; j <= upperLimit; j += i) {
                isPrime[j] = false;
            }
        }

        processed++;
        if (i % (sqrtLimit / 100 + 1) == 0 || i == sqrtLimit) {
            int progress = int(100.0 * i / sqrtLimit);
            emit progressChanged(progress);

            qint64 elapsed = timer.elapsed();
            qint64 estimatedTotal = (elapsed * sqrtLimit) / i;
            qint64 remaining = estimatedTotal - elapsed;
            emit etaChanged(QTime(0, 0).addMSecs(remaining).toString("mm:ss"));
        }
    }

    int primeCount = 0;
    for (int i = 2; i <= upperLimit; ++i) {
        if (isPrime[i])
            ++primeCount;
    }

    emit finished();
    emit logMessage(QString("Prvočísla: Nalezeno %1 prvočísel ≤ %2").arg(primeCount).arg(upperLimit));
    emit logMessage("Výpočet prvočísel dokončen.");
}

void PrimeTask::cancel()
{
    m_cancelled.store(true);
    resume();
}

void PrimeTask::pause()
{
    m_paused.store(true);
    emit logMessage("Výpočet prvočísel pozastaven.");
}

void PrimeTask::resume()
{
    m_paused.store(false);
    m_pauseCondition.wakeAll();
    emit logMessage("Výpočet prvočísel pokračuje.");
}

void PrimeTask::waitIfPaused()
{
    m_mutex.lock();
    while (m_paused.load() && !m_cancelled.load()) {
        m_pauseCondition.wait(&m_mutex);
    }
    m_mutex.unlock();
}
