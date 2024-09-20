/********************************************************************************
** Form generated from reading UI file 'clientmain.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMAIN_H
#define UI_CLIENTMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clientmain
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *btOk;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Clientmain)
    {
        if (Clientmain->objectName().isEmpty())
            Clientmain->setObjectName("Clientmain");
        Clientmain->resize(800, 600);
        centralwidget = new QWidget(Clientmain);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        btOk = new QPushButton(centralwidget);
        btOk->setObjectName("btOk");

        horizontalLayout->addWidget(btOk);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");

        verticalLayout->addWidget(textEdit_2);


        verticalLayout_2->addLayout(verticalLayout);

        Clientmain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Clientmain);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        Clientmain->setMenuBar(menubar);
        statusbar = new QStatusBar(Clientmain);
        statusbar->setObjectName("statusbar");
        Clientmain->setStatusBar(statusbar);

        retranslateUi(Clientmain);

        QMetaObject::connectSlotsByName(Clientmain);
    } // setupUi

    void retranslateUi(QMainWindow *Clientmain)
    {
        Clientmain->setWindowTitle(QCoreApplication::translate("Clientmain", "Clientmain", nullptr));
        btOk->setText(QCoreApplication::translate("Clientmain", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Clientmain", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("Clientmain", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clientmain: public Ui_Clientmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMAIN_H
