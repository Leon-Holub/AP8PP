#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <chrono>
#include <QMutex>
#include <QMutexLocker>

qint64 value = 10;
qint64 upTo = pow(10,8);

QMutex mutex;

class Increment: public QThread{
public:
    void run() override {
        qint64 tmp_value = 0;
        for (qint64 i = 0; i < upTo; i++){
            tmp_value++;
        }
        mutex.lock();
        value += tmp_value;
        mutex.unlock();
        /*
        for (qint64 i = 0; i < upTo; i++){
            QMutexLocker locker (&mutex);
            value++;
        }*/
    }
};

class Decrement: public QThread{
public:
    void run() override {
        qint64 tmp_value = 0;
        for (qint64 i = 0; i < upTo; i++){
            tmp_value--;
        }
        mutex.lock();
        value += tmp_value;
        mutex.unlock();
        /*
        for (qint64 i = 0; i < upTo; i++){
            QMutexLocker locker (&mutex);
            value--;
        }*/
    }
};


using namespace std::chrono;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Increment inc;
    Decrement dec;

    auto start = high_resolution_clock::now();

    inc.start();
    dec.start();

    inc.quit();
    dec.quit();
    inc.wait();
    dec.wait();


    auto stop = high_resolution_clock::now();
    qInfo() << "Work done in " << duration_cast<milliseconds>(stop-start).count();

    qInfo() << "Final value " << value;

    return a.exec();
}
