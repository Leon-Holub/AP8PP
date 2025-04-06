#ifndef PINGCOMMAND_H
#define PINGCOMMAND_H

#include "basecommand.h"

class PingCommand : public BaseCommand {
    Q_OBJECT

public:
    explicit PingCommand(QTextEdit *outputBox, QObject *parent = nullptr);

    void setTarget(const QString &target);
    void setCount(int count);
    void setInfinite(bool infinite);
    void start() override;

private:
    QString target;
    int count = 4;
    bool infinite = false;
};

#endif // PINGCOMMAND_H
