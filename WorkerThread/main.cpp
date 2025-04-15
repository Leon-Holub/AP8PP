#include <QCoreApplication>
#include "controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Controller *pController = new Controller;
    pController->doWork();
    pController->printMsg("Zdar z vetve xd ....");

    return a.exec();
}
