#include "netstatcommand.h"

NetstatCommand::NetstatCommand(QTextEdit *outputBox, QObject *parent): BaseCommand(outputBox, parent)
{
    outputColor = QColor("blue");
}

void NetstatCommand::setA(bool a)
{
    _a = a;
}

void NetstatCommand::setN(bool n)
{
    _n = n;
}

void NetstatCommand::setO(bool o)
{
    _o = o;
}

void NetstatCommand::start()
{
    if(isRunning()){
        printText("Proces již běží.");
        return;
    }


    QStringList arguments;
    if (_a) arguments << "-a";
    if (_n) arguments << "-n";
    if (_o) arguments << "-o";

    process.start(command, arguments);
    printText("Spouštím: " + command + " " + arguments.join(' '));

    emit runningChanged(true);
}




