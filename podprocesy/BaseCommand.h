#ifndef BASECOMMAND_H
#define BASECOMMAND_H
#include <QObject>
#include <QProcess>
#include <QTextEdit>
#include <QColor>

class BaseCommand : public QObject {
    Q_OBJECT

public:
    explicit BaseCommand(QTextEdit *outputBox, QObject *parent = nullptr);
    virtual ~BaseCommand() = default;

    virtual void start() = 0;
    virtual void stop();

    void printText(const QString &text);
    bool isRunning() const;

protected:
    QProcess process;
    QTextEdit *outputBox;
    QColor outputColor = Qt::black;

signals:
    void runningChanged(bool running);

protected slots:
    void readOutput();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);
};

#endif // BASECOMMAND_H
