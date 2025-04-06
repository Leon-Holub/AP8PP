#include "basecommand.h"

BaseCommand::BaseCommand(QTextEdit *outputBox, QObject *parent)
    : QObject(parent), outputBox(outputBox)
{
    // Napojení signálů jen jednou – pro všechny potomky
    connect(&process, &QProcess::readyReadStandardOutput, this, &BaseCommand::readOutput);
    connect(&process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &BaseCommand::processFinished);
}

void BaseCommand::stop() {
    if (process.state() != QProcess::NotRunning) {
        process.kill();
        printText("Proces byl ukončen.");
        emit runningChanged(false);
    }
}

void BaseCommand::printText(const QString &text)
{
    if(outputBox){
        outputBox->append(QString("<span style='color:%1;'>%2</span>").arg(outputColor.name()).arg(text));
    }
}

bool BaseCommand::isRunning() const {
    return process.state() != QProcess::NotRunning;
}

void BaseCommand::readOutput() {
    if (!outputBox) return;

    QByteArray output = process.readAllStandardOutput();
    QString text = QString::fromLocal8Bit(output).toHtmlEscaped();
    printText(text);
}

void BaseCommand::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
    if (!outputBox) return;

    QString message;
    QString color = outputColor.name();

    if (exitStatus == QProcess::CrashExit || exitCode != 0) {
        message = QString("Proces byl ukončen předčasně (exit code: %1)").arg(exitCode);
        color = "red";
    } else {
        message = QString("Proces dokončen úspěšně (exit code: %1)").arg(exitCode);
    }

    printText("<br>");
    outputBox->append(QString("<span style='color:%1;'>%2</span>").arg(color, message));
    printText("<br>");
    emit runningChanged(false);
}

