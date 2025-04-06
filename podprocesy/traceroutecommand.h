#ifndef TRACEROUTECOMMAND_H
#define TRACEROUTECOMMAND_H

#include "basecommand.h"

class TracerouteCommand : public BaseCommand {
    Q_OBJECT

public:
    explicit TracerouteCommand(QTextEdit *outputBox, QObject *parent = nullptr);

    void setTarget(const QString &target);
    void start() override;

private:
    QString target;
};

#endif // TRACEROUTECOMMAND_H
