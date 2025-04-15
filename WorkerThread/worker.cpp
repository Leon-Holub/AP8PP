#include "worker.h"
#include <QThread>
#include <QDebug>

Worker::Worker(QObject *parent)
    : QObject{parent}
{}

void Worker::printMessage(QString msg)
{
    qInfo() << msg << " from thread ID: " << QThread::currentThreadId();
}

void Worker::doWork()
{
    qInfo() << "Hello from thread ID: " << QThread::currentThreadId();
    for (int i = 0; i < 10; ++i) {
        qInfo() << "Number " << i << " from thread ID: " << QThread::currentThreadId();
    }
    emit workDone();
}
