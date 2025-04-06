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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *StateText;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *NumberTextField;
    QPushButton *startButton;
    QPushButton *PauseButton;
    QProgressBar *progressBar;
    QLabel *ResultText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 200);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        StateText = new QLabel(centralwidget);
        StateText->setObjectName("StateText");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StateText->sizePolicy().hasHeightForWidth());
        StateText->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        StateText->setFont(font);
        StateText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(StateText);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout_4->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NumberTextField = new QLineEdit(centralwidget);
        NumberTextField->setObjectName("NumberTextField");

        horizontalLayout->addWidget(NumberTextField);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        horizontalLayout->addWidget(startButton);

        PauseButton = new QPushButton(centralwidget);
        PauseButton->setObjectName("PauseButton");

        horizontalLayout->addWidget(PauseButton);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout_4);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        ResultText = new QLabel(centralwidget);
        ResultText->setObjectName("ResultText");
        sizePolicy.setHeightForWidth(ResultText->sizePolicy().hasHeightForWidth());
        ResultText->setSizePolicy(sizePolicy);
        ResultText->setFont(font);
        ResultText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(ResultText);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Zpracov\303\241n\303\255 \303\272lohy v dob\304\233 ne\304\215innosti aplikace", nullptr));
        StateText->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\304\214\303\255slo k zjis\305\241t\304\233n\303\255", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        PauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        ResultText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
