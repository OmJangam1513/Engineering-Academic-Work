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
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;
    QPushButton *DDA_Line_Clicked;
    QPlainTextEdit *plainTextEdit_6;
    QPushButton *Bresenha_Circle_clicked;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *Display;
    QPlainTextEdit *plainTextEdit_7;
    QLabel *label_8;
    QPushButton *Triangle;
    QPushButton *Inner_Circle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(814, 552);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 30, 21, 17));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(670, 20, 104, 31));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(670, 70, 104, 31));
        plainTextEdit_3 = new QPlainTextEdit(centralwidget);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(670, 110, 104, 31));
        plainTextEdit_4 = new QPlainTextEdit(centralwidget);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        plainTextEdit_4->setGeometry(QRect(670, 150, 104, 31));
        plainTextEdit_5 = new QPlainTextEdit(centralwidget);
        plainTextEdit_5->setObjectName(QString::fromUtf8("plainTextEdit_5"));
        plainTextEdit_5->setGeometry(QRect(670, 250, 104, 31));
        DDA_Line_Clicked = new QPushButton(centralwidget);
        DDA_Line_Clicked->setObjectName(QString::fromUtf8("DDA_Line_Clicked"));
        DDA_Line_Clicked->setGeometry(QRect(680, 200, 89, 25));
        plainTextEdit_6 = new QPlainTextEdit(centralwidget);
        plainTextEdit_6->setObjectName(QString::fromUtf8("plainTextEdit_6"));
        plainTextEdit_6->setGeometry(QRect(670, 290, 104, 31));
        Bresenha_Circle_clicked = new QPushButton(centralwidget);
        Bresenha_Circle_clicked->setObjectName(QString::fromUtf8("Bresenha_Circle_clicked"));
        Bresenha_Circle_clicked->setGeometry(QRect(650, 390, 121, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 80, 21, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 120, 20, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 150, 31, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(620, 260, 21, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(620, 300, 21, 17));
        Display = new QLabel(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setGeometry(QRect(20, 30, 581, 451));
        plainTextEdit_7 = new QPlainTextEdit(centralwidget);
        plainTextEdit_7->setObjectName(QString::fromUtf8("plainTextEdit_7"));
        plainTextEdit_7->setGeometry(QRect(670, 340, 104, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(620, 350, 21, 20));
        Triangle = new QPushButton(centralwidget);
        Triangle->setObjectName(QString::fromUtf8("Triangle"));
        Triangle->setGeometry(QRect(670, 420, 89, 25));
        Inner_Circle = new QPushButton(centralwidget);
        Inner_Circle->setObjectName(QString::fromUtf8("Inner_Circle"));
        Inner_Circle->setGeometry(QRect(670, 450, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 814, 22));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "x1", nullptr));
        DDA_Line_Clicked->setText(QCoreApplication::translate("MainWindow", "DDA Line", nullptr));
        Bresenha_Circle_clicked->setText(QCoreApplication::translate("MainWindow", "Bresenham Circle", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "y1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "xc", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "yc", nullptr));
        Display->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        Triangle->setText(QCoreApplication::translate("MainWindow", "Triangel", nullptr));
        Inner_Circle->setText(QCoreApplication::translate("MainWindow", "Inner Cirlce", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
