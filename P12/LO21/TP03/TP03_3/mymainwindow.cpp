#include "mymainwindow.h"
#include "ui_mainwindow.h"


void MyMainWindow::createActions(){
    playAct = new QAction(tr("&Play"), this);
    pauseAct = new QAction(tr("&Pause"), this);
    resetAct = new QAction(tr("&Reset"), this);
    quitAct = new QAction(tr("&Quit"), this);
    QObject::connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));
    aboutAct = new QAction(tr("&About"), this);
}

void MyMainWindow::createMenus(){
    animationMenu=menuBar()->addMenu(tr("&Animation"));
    animationMenu->addAction(playAct);
    animationMenu->addAction(pauseAct);
    animationMenu->addAction(resetAct);
    animationMenu->addAction(quitAct);
    animationMenu->addSeparator();
    animationMenu=menuBar()->addMenu(tr("&Help"));
    animationMenu->addAction(aboutAct);
}
