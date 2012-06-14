#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        initialisation();
    }

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::initialisation() {
    ecran = "";
    ui->ecran->setText("");
    ui->ecran->setStyleSheet("background-color: white");
    pile = new Pile();
}


void MainWindow::connections_buttons() {
    connect(ui->button_0, SIGNAL(clicked()), this, SLOT(affiche_0()));
    connect(ui->button_1, SIGNAL(clicked()), this, SLOT(affiche_1()));
    connect(ui->button_2, SIGNAL(clicked()), this, SLOT(affiche_2()));
    connect(ui->button_3, SIGNAL(clicked()), this, SLOT(affiche_3()));
    connect(ui->button_4, SIGNAL(clicked()), this, SLOT(affiche_4()));
    connect(ui->button_5, SIGNAL(clicked()), this, SLOT(affiche_5()));
    connect(ui->button_6, SIGNAL(clicked()), this, SLOT(affiche_6()));
    connect(ui->button_7, SIGNAL(clicked()), this, SLOT(affiche_7()));
    connect(ui->button_8, SIGNAL(clicked()), this, SLOT(affiche_8()));
    connect(ui->button_9, SIGNAL(clicked()), this, SLOT(affiche_9()));
    connect(ui->button_plus, SIGNAL(clicked()), this, SLOT(affiche_plus()));
    connect(ui->button_moins, SIGNAL(clicked()), this, SLOT(affiche_moins()));
    connect(ui->button_fois, SIGNAL(clicked()), this, SLOT(affiche_fois()));
    connect(ui->button_divise, SIGNAL(clicked()), this, SLOT(affiche_divise()));
    connect(ui->button_space, SIGNAL(clicked()), this, SLOT(affiche_space()));
    connect(ui->button_egal, SIGNAL(clicked()), this, SLOT(press_egal()));
    connect(ui->button_clear, SIGNAL(clicked()), this, SLOT(press_clear()));
    connect(ui->button_point, SIGNAL(clicked()), this, SLOT(press_point()));
    connect(ui->button_rationnel, SIGNAL(clicked()), this, SLOT(press_rationnel()));
    connect(ui->button_dollar, SIGNAL(clicked()), this, SLOT(press_dollar()));
    connect(ui->radio_complexes, SIGNAL(clicked()), this, SLOT(press_radio_complexes()));
    connect(ui->radio_entiers, SIGNAL(clicked()), this, SLOT(press_radio_entiers()));
    connect(ui->radio_rationnels, SIGNAL(clicked()), this, SLOT(press_radio_rationnels()));
    connect(ui->radio_reels, SIGNAL(clicked()), this, SLOT(press_radio_reels()));
}

void MainWindow::affiche_0() {
    ecran=ecran.append("0");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_1() {
    ecran=ecran.append("1");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_2() {
    ecran=ecran.append("2");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_3() {
    ecran=ecran.append("3");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_4() {
    ecran=ecran.append("4");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_5() {
    ecran=ecran.append("5");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_6() {
    ecran=ecran.append("6");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_7() {
    ecran=ecran.append("7");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_8() {
    ecran=ecran.append("8");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_9() {
    ecran=ecran.append("9");
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_plus() {
    verif_operateur(QString("+"));
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_moins() {
    verif_operateur(QString("-"));
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_divise() {
    verif_operateur(QString("/"));
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_fois() {
    verif_operateur(QString("*"));
    ui->ecran->setText(ecran);
}
void MainWindow::affiche_space() {
    if(QString::compare(ecran.at(ecran.length()-1), " "))
        ecran=ecran.append(" ");
    ui->ecran->setText(ecran);
}

void MainWindow::press_clear() {
    ecran="";
    pile->clear();
    ui->ecran->setText(ecran);
    ui->ecran_pile->setText(ecran);
}

void MainWindow::press_point() {
    ecran=ecran.append(".");
    ui->ecran->setText(ecran);
}

void MainWindow::press_dollar() {
    ecran=ecran.append("$");
    ui->ecran->setText(ecran);
}

void MainWindow::press_rationnel() {
    ecran=ecran.append("/");
    ui->ecran->setText(ecran);
}

void MainWindow::press_egal() {
    ui->ecran->setText(ecran);
    int mode;
    if(ui->radio_entiers->isChecked()) {
        mode = 1;
    } else if(ui->radio_complexes->isChecked()) {
        mode = 2;
    } else if(ui->radio_rationnels->isChecked()) {
        mode = 3;
    } else if(ui->radio_reels->isChecked()) {
        mode = 4;
    }
    pile->parsage(ecran, mode);
    refresh_ecran();
}

void MainWindow::press_radio_entiers() {
    ui->button_dollar->setEnabled(FALSE);
    ui->button_rationnel->setEnabled(FALSE);
    ui->button_point->setEnabled(FALSE);
    ecran="";
    pile->clear();
    ui->ecran->setText(ecran);
    ui->ecran_pile->setText(ecran);
}

void MainWindow::press_radio_rationnels() {
    ui->button_dollar->setEnabled(FALSE);
    ui->button_rationnel->setEnabled(TRUE);
    ui->button_point->setEnabled(FALSE);
    ecran="";
    pile->clear();
    ui->ecran->setText(ecran);
    ui->ecran_pile->setText(ecran);
}

void MainWindow::press_radio_reels() {
    ui->button_dollar->setEnabled(FALSE);
    ui->button_rationnel->setEnabled(FALSE);
    ui->button_point->setEnabled(TRUE);
    ecran="";
    pile->clear();
    ui->ecran->setText(ecran);
    ui->ecran_pile->setText(ecran);
}

void MainWindow::press_radio_complexes() {
    ui->button_dollar->setEnabled(TRUE);
    ui->button_rationnel->setEnabled(FALSE);
    ui->button_point->setEnabled(FALSE);
    ecran="";
    pile->clear();
    ui->ecran->setText(ecran);
    ui->ecran_pile->setText(ecran);
}

void MainWindow::refresh_ecran() {
    QString s = "Pile : ";
    if(!pile->isEmpty()) {
        //pile->pop();
        while(!pile->isEmpty()) {
            s = s.append("\n");
            s = s.append(pile->top()->afficher());
            pile->pop();
        }
    }
    ui->ecran_pile->setText(s);
}

bool MainWindow::verif_operateur(QString s) {
    if(ecran.length() > 1 && QString::compare(ecran.at(ecran.length()-1), " "))
        ecran=ecran.append(" ");
    ecran=ecran.append(s);
    ecran=ecran.append(" ");
    return true;
}

