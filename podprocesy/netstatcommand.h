#ifndef NETSTATCOMMAND_H
#define NETSTATCOMMAND_H

#include "BaseCommand.h"


class NetstatCommand: public BaseCommand {
    Q_OBJECT

public:
    NetstatCommand(QTextEdit *outputBox, QObject *parent = nullptr);

    void setA(bool a);
    void setN(bool n);
    void setO(bool o);
    void start() override;

private:
    bool _a = false;
    bool _n = false;
    bool _o = false;
    QString command = "netstat";
};

#endif // NETSTATCOMMAND_H
