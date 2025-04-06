#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <memory>
#include "sprite.h"

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

private slots:
    void on_actionAdd_sprite_triggered();

    void on_actionRemove_last_triggered();

    void on_actionRemove_all_triggered();

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    QList<std::shared_ptr <Sprite>> sprites;
};
#endif // MAINWINDOW_H
