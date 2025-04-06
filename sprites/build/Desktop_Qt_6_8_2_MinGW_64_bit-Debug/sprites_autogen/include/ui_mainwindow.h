/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_sprite;
    QAction *actionRemove_last;
    QAction *actionRemove_all;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuSprites;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAdd_sprite = new QAction(MainWindow);
        actionAdd_sprite->setObjectName("actionAdd_sprite");
        actionRemove_last = new QAction(MainWindow);
        actionRemove_last->setObjectName("actionRemove_last");
        actionRemove_all = new QAction(MainWindow);
        actionRemove_all->setObjectName("actionRemove_all");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuSprites = new QMenu(menubar);
        menuSprites->setObjectName("menuSprites");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSprites->menuAction());
        menuSprites->addAction(actionAdd_sprite);
        menuSprites->addAction(actionRemove_last);
        menuSprites->addAction(actionRemove_all);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAdd_sprite->setText(QCoreApplication::translate("MainWindow", "Add sprite", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_sprite->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove_last->setText(QCoreApplication::translate("MainWindow", "Remove last", nullptr));
#if QT_CONFIG(shortcut)
        actionRemove_last->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove_all->setText(QCoreApplication::translate("MainWindow", "Remove all", nullptr));
#if QT_CONFIG(shortcut)
        actionRemove_all->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        menuSprites->setTitle(QCoreApplication::translate("MainWindow", "Sprites", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
