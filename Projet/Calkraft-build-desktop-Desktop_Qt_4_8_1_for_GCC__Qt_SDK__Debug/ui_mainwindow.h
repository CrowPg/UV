/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Jun 13 23:03:10 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMode_de_Constantes;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *ecran_pile;
    QLabel *ecran;
    QGridLayout *gridLayout;
    QPushButton *button_0;
    QPushButton *button_9;
    QPushButton *button_8;
    QPushButton *button_1;
    QPushButton *button_4;
    QPushButton *button_7;
    QPushButton *button_5;
    QPushButton *button_2;
    QPushButton *button_6;
    QPushButton *button_3;
    QPushButton *button_plus;
    QPushButton *button_fois;
    QPushButton *button_divise;
    QPushButton *button_moins;
    QPushButton *button_space;
    QPushButton *button_clear;
    QPushButton *button_egal;
    QPushButton *button_point;
    QPushButton *button_rationnel;
    QPushButton *button_dollar;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radio_entiers;
    QRadioButton *radio_reels;
    QRadioButton *radio_complexes;
    QRadioButton *radio_rationnels;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(326, 490);
        actionMode_de_Constantes = new QAction(MainWindow);
        actionMode_de_Constantes->setObjectName(QString::fromUtf8("actionMode_de_Constantes"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 2, 309, 352));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ecran_pile = new QTextBrowser(verticalLayoutWidget);
        ecran_pile->setObjectName(QString::fromUtf8("ecran_pile"));

        verticalLayout_2->addWidget(ecran_pile);


        verticalLayout->addLayout(verticalLayout_2);

        ecran = new QLabel(verticalLayoutWidget);
        ecran->setObjectName(QString::fromUtf8("ecran"));

        verticalLayout->addWidget(ecran);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button_0 = new QPushButton(verticalLayoutWidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));

        gridLayout->addWidget(button_0, 4, 0, 1, 2);

        button_9 = new QPushButton(verticalLayoutWidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));

        gridLayout->addWidget(button_9, 1, 2, 1, 1);

        button_8 = new QPushButton(verticalLayoutWidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));

        gridLayout->addWidget(button_8, 1, 1, 1, 1);

        button_1 = new QPushButton(verticalLayoutWidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));

        gridLayout->addWidget(button_1, 3, 0, 1, 1);

        button_4 = new QPushButton(verticalLayoutWidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));

        gridLayout->addWidget(button_4, 2, 0, 1, 1);

        button_7 = new QPushButton(verticalLayoutWidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));

        gridLayout->addWidget(button_7, 1, 0, 1, 1);

        button_5 = new QPushButton(verticalLayoutWidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));

        gridLayout->addWidget(button_5, 2, 1, 1, 1);

        button_2 = new QPushButton(verticalLayoutWidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));

        gridLayout->addWidget(button_2, 3, 1, 1, 1);

        button_6 = new QPushButton(verticalLayoutWidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));

        gridLayout->addWidget(button_6, 2, 2, 1, 1);

        button_3 = new QPushButton(verticalLayoutWidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));

        gridLayout->addWidget(button_3, 3, 2, 1, 1);

        button_plus = new QPushButton(verticalLayoutWidget);
        button_plus->setObjectName(QString::fromUtf8("button_plus"));

        gridLayout->addWidget(button_plus, 1, 3, 1, 1);

        button_fois = new QPushButton(verticalLayoutWidget);
        button_fois->setObjectName(QString::fromUtf8("button_fois"));

        gridLayout->addWidget(button_fois, 3, 3, 1, 1);

        button_divise = new QPushButton(verticalLayoutWidget);
        button_divise->setObjectName(QString::fromUtf8("button_divise"));

        gridLayout->addWidget(button_divise, 4, 3, 1, 1);

        button_moins = new QPushButton(verticalLayoutWidget);
        button_moins->setObjectName(QString::fromUtf8("button_moins"));

        gridLayout->addWidget(button_moins, 2, 3, 1, 1);

        button_space = new QPushButton(verticalLayoutWidget);
        button_space->setObjectName(QString::fromUtf8("button_space"));

        gridLayout->addWidget(button_space, 5, 0, 1, 4);

        button_clear = new QPushButton(verticalLayoutWidget);
        button_clear->setObjectName(QString::fromUtf8("button_clear"));

        gridLayout->addWidget(button_clear, 0, 3, 1, 1);

        button_egal = new QPushButton(verticalLayoutWidget);
        button_egal->setObjectName(QString::fromUtf8("button_egal"));

        gridLayout->addWidget(button_egal, 4, 2, 1, 1);

        button_point = new QPushButton(verticalLayoutWidget);
        button_point->setObjectName(QString::fromUtf8("button_point"));

        gridLayout->addWidget(button_point, 0, 0, 1, 1);

        button_rationnel = new QPushButton(verticalLayoutWidget);
        button_rationnel->setObjectName(QString::fromUtf8("button_rationnel"));

        gridLayout->addWidget(button_rationnel, 0, 1, 1, 1);

        button_dollar = new QPushButton(verticalLayoutWidget);
        button_dollar->setObjectName(QString::fromUtf8("button_dollar"));

        gridLayout->addWidget(button_dollar, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 360, 161, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        radio_entiers = new QRadioButton(verticalLayoutWidget_2);
        radio_entiers->setObjectName(QString::fromUtf8("radio_entiers"));

        verticalLayout_3->addWidget(radio_entiers);

        radio_reels = new QRadioButton(verticalLayoutWidget_2);
        radio_reels->setObjectName(QString::fromUtf8("radio_reels"));

        verticalLayout_3->addWidget(radio_reels);

        radio_complexes = new QRadioButton(verticalLayoutWidget_2);
        radio_complexes->setObjectName(QString::fromUtf8("radio_complexes"));

        verticalLayout_3->addWidget(radio_complexes);

        radio_rationnels = new QRadioButton(verticalLayoutWidget_2);
        radio_rationnels->setObjectName(QString::fromUtf8("radio_rationnels"));

        verticalLayout_3->addWidget(radio_rationnels);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 326, 22));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionMode_de_Constantes);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionMode_de_Constantes->setText(QApplication::translate("MainWindow", "Mode de Constantes", 0, QApplication::UnicodeUTF8));
        ecran->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        button_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        button_0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        button_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        button_9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        button_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        button_8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        button_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        button_1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        button_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        button_4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        button_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        button_7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        button_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        button_5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        button_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        button_2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        button_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        button_6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        button_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        button_3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        button_plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        button_plus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        button_fois->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        button_fois->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        button_divise->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        button_divise->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        button_moins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        button_moins->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        button_space->setText(QApplication::translate("MainWindow", "SPACE", 0, QApplication::UnicodeUTF8));
        button_space->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        button_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        button_clear->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        button_egal->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        button_egal->setShortcut(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        button_point->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        button_point->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        button_rationnel->setText(QApplication::translate("MainWindow", "r", 0, QApplication::UnicodeUTF8));
        button_rationnel->setShortcut(QApplication::translate("MainWindow", "R", 0, QApplication::UnicodeUTF8));
        button_dollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        button_dollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        radio_entiers->setText(QApplication::translate("MainWindow", "Entiers", 0, QApplication::UnicodeUTF8));
        radio_reels->setText(QApplication::translate("MainWindow", "R\303\251els", 0, QApplication::UnicodeUTF8));
        radio_complexes->setText(QApplication::translate("MainWindow", "Complexes", 0, QApplication::UnicodeUTF8));
        radio_rationnels->setText(QApplication::translate("MainWindow", "Rationnels", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
