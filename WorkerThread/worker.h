#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void printMessage(QString msg);
    void doWork();

signals:
    void workDone();
};

#endif // WORKER_H
