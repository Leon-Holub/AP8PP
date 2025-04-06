#include "pingcommand.h"

PingCommand::PingCommand(QTextEdit *outputBox, QObject *parent)
    : BaseCommand(outputBox, parent)
{
    outputColor = QColor("green");
}

void PingCommand::setTarget(const QString &target) {
    this->target = target.trimmed();
}

void PingCommand::setCount(int count) {
    this->count = count;
}

void PingCommand::setInfinite(bool infinite) {
    this->infinite = infinite;
}

void PingCommand::start() {
    if (isRunning()) {
        printText("Proces již běží.");
        return;
    }

    if (target.isEmpty()) {
        printText("Zadejte cílovou IP nebo doménu.");
        return;
    }
    QString command = "ping";

#ifdef Q_OS_WIN
    QStringList arguments;
    if (!infinite)
        arguments << "-n" << QString::number(count);  // Windows: -n <count>
    else
        arguments << "-n" << "999999";
#else
    QStringList arguments;
    if (!infinite)
        arguments << "-c" << QString::number(count);  // Linux/Mac: -c <count>
#endif

    arguments << target;

    process.start(command, arguments);

    printText("Spouštím ping na " + target);
    emit runningChanged(true);
}
