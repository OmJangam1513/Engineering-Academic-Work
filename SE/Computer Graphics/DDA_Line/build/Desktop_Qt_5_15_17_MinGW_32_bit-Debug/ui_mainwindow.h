/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *DDA_line;
    QLabel *display;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPlainTextEdit *plainTextEdit_5;
    QPlainTextEdit *plainTextEdit_6;
    QPlainTextEdit *plainTextEdit_7;
    QPushButton *B_Circle;
    QPushButton *M_Circle;
    QPushButton *create_1;
    QPushButton *create_2;
    QPushButton *clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(560, 10, 104, 31));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(560, 60, 104, 31));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(560, 110, 104, 31));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(560, 160, 104, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 20, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(530, 70, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(530, 120, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(530, 170, 67, 17));
        DDA_line = new QPushButton(centralwidget);
        DDA_line->setObjectName(QString::fromUtf8("DDA_line"));
        DDA_line->setGeometry(QRect(560, 210, 89, 25));
        display = new QLabel(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setGeometry(QRect(0, 0, 500, 500));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 270, 67, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(520, 320, 67, 17));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(520, 370, 67, 17));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName(QString::fromUtf8("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(550, 360, 104, 31));
        plainTextEdit_6 = new QPlainTextEdit(centralwidget);
        plainTextEdit_6->setObjectName(QString::fromUtf8("plainTextEdit_6"));
        plainTextEdit_6->setGeometry(QRect(550, 310, 104, 31));
        plainTextEdit_7 = new QPlainTextEdit(centralwidget);
        plainTextEdit_7->setObjectName(QString::fromUtf8("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(550, 260, 104, 31));
        B_Circle = new QPushButton(centralwidget);
        B_Circle->setObjectName(QString::fromUtf8("B_Circle"));
        B_Circle->setGeometry(QRect(500, 410, 151, 25));
        M_Circle = new QPushButton(centralwidget);
        M_Circle->setObjectName(QString::fromUtf8("M_Circle"));
        M_Circle->setGeometry(QRect(500, 440, 151, 25));
        create_1 = new QPushButton(centralwidget);
        create_1->setObjectName(QString::fromUtf8("create_1"));
        create_1->setGeometry(QRect(560, 470, 89, 25));
        create_2 = new QPushButton(centralwidget);
        create_2->setObjectName(QString::fromUtf8("create_2"));
        create_2->setGeometry(QRect(560, 500, 89, 25));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(560, 530, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y2", nullptr));
        DDA_line->setText(QCoreApplication::translate("MainWindow", "DDA Line", nullptr));
        display->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "XC", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "YC", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        B_Circle->setText(QCoreApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        M_Circle->setText(QCoreApplication::translate("MainWindow", "Midpoint Circle", nullptr));
        create_1->setText(QCoreApplication::translate("MainWindow", "Create 1", nullptr));
        create_2->setText(QCoreApplication::translate("MainWindow", "Create 2", nullptr));
        clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
