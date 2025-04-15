#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include "worker.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void printMsg(QString msg);
    void doWork();

signals:
    void printMsgInWT(QString msg);
    void doSomeWorkInWT();

private:
    QThread *pWorkerThread;
    Worker *pWorker;
};

#endif // CONTROLLER_H
