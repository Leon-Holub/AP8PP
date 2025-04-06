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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *netstat_a;
    QCheckBox *netstat_n;
    QCheckBox *netstat_o;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *netstat_start;
    QPushButton *netstat_stop;
    QFrame *line_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *ping_ip;
    QLabel *label_5;
    QSpinBox *ping_count;
    QCheckBox *ping_infinite;
    QSpacerItem *horizontalSpacer;
    QPushButton *ping_start;
    QPushButton *ping_stop;
    QFrame *line;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *traceroute_ip;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *traceroute_start;
    QPushButton *traceroute_stop;
    QFrame *line_3;
    QLabel *label_7;
    QTextEdit *outprint;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(801, 723);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        netstat_a = new QCheckBox(groupBox);
        netstat_a->setObjectName("netstat_a");

        verticalLayout_4->addWidget(netstat_a);

        netstat_n = new QCheckBox(groupBox);
        netstat_n->setObjectName("netstat_n");

        verticalLayout_4->addWidget(netstat_n);

        netstat_o = new QCheckBox(groupBox);
        netstat_o->setObjectName("netstat_o");

        verticalLayout_4->addWidget(netstat_o);


        horizontalLayout->addWidget(groupBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        netstat_start = new QPushButton(centralwidget);
        netstat_start->setObjectName("netstat_start");

        horizontalLayout->addWidget(netstat_start);

        netstat_stop = new QPushButton(centralwidget);
        netstat_stop->setObjectName("netstat_stop");
        netstat_stop->setEnabled(false);

        horizontalLayout->addWidget(netstat_stop);


        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_4);

        ping_ip = new QLineEdit(groupBox_2);
        ping_ip->setObjectName("ping_ip");

        verticalLayout_3->addWidget(ping_ip);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_5);

        ping_count = new QSpinBox(groupBox_2);
        ping_count->setObjectName("ping_count");
        ping_count->setValue(4);

        verticalLayout_3->addWidget(ping_count);

        ping_infinite = new QCheckBox(groupBox_2);
        ping_infinite->setObjectName("ping_infinite");

        verticalLayout_3->addWidget(ping_infinite);


        horizontalLayout_4->addWidget(groupBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        ping_start = new QPushButton(centralwidget);
        ping_start->setObjectName("ping_start");

        horizontalLayout_4->addWidget(ping_start);

        ping_stop = new QPushButton(centralwidget);
        ping_stop->setObjectName("ping_stop");
        ping_stop->setEnabled(false);

        horizontalLayout_4->addWidget(ping_stop);


        verticalLayout->addLayout(horizontalLayout_4);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_6);

        traceroute_ip = new QLineEdit(groupBox_3);
        traceroute_ip->setObjectName("traceroute_ip");

        verticalLayout_2->addWidget(traceroute_ip);


        horizontalLayout_3->addWidget(groupBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        traceroute_start = new QPushButton(centralwidget);
        traceroute_start->setObjectName("traceroute_start");

        horizontalLayout_3->addWidget(traceroute_start);

        traceroute_stop = new QPushButton(centralwidget);
        traceroute_stop->setObjectName("traceroute_stop");
        traceroute_stop->setEnabled(false);

        horizontalLayout_3->addWidget(traceroute_stop);


        verticalLayout->addLayout(horizontalLayout_3);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        outprint = new QTextEdit(centralwidget);
        outprint->setObjectName("outprint");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(outprint->sizePolicy().hasHeightForWidth());
        outprint->setSizePolicy(sizePolicy2);
        outprint->setReadOnly(true);

        verticalLayout->addWidget(outprint);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 801, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "NETSTAT", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Nastaven\303\255", nullptr));
        netstat_a->setText(QCoreApplication::translate("MainWindow", "Zobrazit v\305\241echny p\305\231ipojen\303\255 a naslouchaj\303\255c\303\255 porty", nullptr));
        netstat_n->setText(QCoreApplication::translate("MainWindow", "Zobrazit adresy \304\215\303\255seln\304\233, ne jako dom\303\251nov\303\241 jm\303\251na", nullptr));
        netstat_o->setText(QCoreApplication::translate("MainWindow", "Zobrazit PID u ka\305\276d\303\251ho p\305\231ipojen\303\255", nullptr));
        netstat_start->setText(QCoreApplication::translate("MainWindow", "Spustit", nullptr));
        netstat_stop->setText(QCoreApplication::translate("MainWindow", "Zastavit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PING", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Nastaven\303\255", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "C\303\255lov\303\241 IP adresa", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Po\304\215et opakov\303\241n\303\255", nullptr));
        ping_infinite->setText(QCoreApplication::translate("MainWindow", "nekone\304\215n\303\251 opakov\303\241n\303\255", nullptr));
        ping_start->setText(QCoreApplication::translate("MainWindow", "Spustit", nullptr));
        ping_stop->setText(QCoreApplication::translate("MainWindow", "Zastavit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TRACEROUTE ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Nastaven\303\255", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "C\303\255lov\303\241 IP/Dom\303\251na", nullptr));
        traceroute_start->setText(QCoreApplication::translate("MainWindow", "Spustit", nullptr));
        traceroute_stop->setText(QCoreApplication::translate("MainWindow", "Zastavit", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "V\303\275stup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
