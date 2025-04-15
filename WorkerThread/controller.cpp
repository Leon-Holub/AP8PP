#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    pWorkerThread = new QThread;
    pWorker = new Worker;
    pWorker->moveToThread(pWorkerThread);

    connect(this, &Controller::doSomeWorkInWT, pWorker, &Worker::doWork);
    connect(this, &Controller::printMsgInWT, pWorker, &Worker::printMessage);
    connect(pWorkerThread, &QThread::finished, pWorker, &Worker::deleteLater);

    pWorkerThread->start();
}

Controller::~Controller()
{
    pWorkerThread->quit();

    pWorkerThread->wait();

    delete pWorkerThread;
}

void Controller::printMsg(QString msg)
{
    emit printMsgInWT(msg);
}

void Controller::doWork()
{
    emit doSomeWorkInWT();
}
