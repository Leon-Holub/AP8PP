#include "traceroutecommand.h"
#include <QDebug>

TracerouteCommand::TracerouteCommand(QTextEdit *outputBox, QObject *parent)
    : BaseCommand(outputBox, parent)
{
    outputColor = QColor("orange");  // nebo "#FFD700" pro víc žlutou
}

void TracerouteCommand::setTarget(const QString &target) {
    this->target = target.trimmed();
}

void TracerouteCommand::start() {
    if (isRunning()) {
        printText("Proces již běží.");
        return;
    }

    if (target.isEmpty()) {
        printText("Zadejte cílovou IP nebo doménu.");
        return;
    }

#ifdef Q_OS_WIN
    QString command = "tracert";
#else
    QString command = "traceroute";
#endif

    QStringList arguments;
    arguments << target;

    process.start(command, arguments);

    printText("Spouštím traceroute na " + target);

    emit runningChanged(true);
}
