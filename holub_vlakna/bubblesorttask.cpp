#include "bubblesorttask.h"
#include <QDateTime>
#include <QThread>
#include <vector>
#include <random>
#include <algorithm>

BubbleSortTask::BubbleSortTask(int size, QObject *parent)
    : QObject{parent}, dataSize(size)
{}

void BubbleSortTask::run()
{
    QElapsedTimer timer;
    timer.start();

    emit logMessage(QString("Spouštím Bubble Sort nad %1 prvky")
                        .arg(QString::number(dataSize)));

    // Náhodné vstupní pole
    std::vector<int> data(dataSize);
    std::mt19937 rng(QDateTime::currentMSecsSinceEpoch());
    std::uniform_int_distribution<> dist(1, 1000000);
    std::generate(data.begin(), data.end(), [&]() { return dist(rng); });

    int totalPasses = dataSize - 1;

    for (int i = 0; i < totalPasses; ++i) {
        waitIfPaused();
        if (m_cancelled.load()) {
            emit canceled();
            emit logMessage("Bubble Sort byl zrušen.");
            return;
        }

        for (int j = 0; j < totalPasses - i; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }

        if (i % (totalPasses / 100 + 1) == 0 || i == totalPasses - 1) {
            int progress = int(100.0 * i / totalPasses);
            emit progressChanged(progress);

            qint64 elapsed = timer.elapsed();
            qint64 estimatedTotal = (elapsed * totalPasses) / (i + 1);
            qint64 remaining = estimatedTotal - elapsed;
            emit etaChanged(QTime(0, 0).addMSecs(remaining).toString("mm:ss"));
        }
    }

    QString result = "Seřazených 10 prvků: ";
    for (int i = 0; i < std::min(10, dataSize); ++i) {
        result += QString::number(data[i]) + " ";
    }

    emit progressChanged(100);
    emit finished();
    emit logMessage("Bubble Sort výsledek:" + result.trimmed());
    emit logMessage("Bubble Sort dokončen.");
}

void BubbleSortTask::cancel()
{
    m_cancelled.store(true);
    resume();
}

void BubbleSortTask::pause()
{
    m_paused.store(true);
    emit logMessage("Bubble Sort pozastaven.");
}

void BubbleSortTask::resume()
{
    m_paused.store(false);
    m_pauseCondition.wakeAll();
    emit logMessage("Bubble Sort pokračuje.");
}

void BubbleSortTask::waitIfPaused()
{
    m_mutex.lock();
    while (m_paused.load() && !m_cancelled.load()) {
        m_pauseCondition.wait(&m_mutex);
    }
    m_mutex.unlock();
}
