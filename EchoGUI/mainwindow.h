#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void updateUI(bool enabled);

private slots:
    void on_pushButton_clicked();
    void onEchoStateChanged(QProcess::ProcessState state);
    void onEchoErrorOccured(QProcess::ProcessError error);

private:
    Ui::MainWindow *ui;
    QProcess echo;
};
#endif // MAINWINDOW_H
