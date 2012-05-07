#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
     void play();
     void pause();
     void reset();
     void quit();
     void about();

private:
     void createActions();
     void createMenus();

     QMenu *animationMenu;
     QMenu *helpMenu;
     QAction *playAct;
     QAction *pauseAct;
     QAction *resetAct;
     QAction *quitAct;
     QAction *aboutAct;

};

#endif // MYMAINWINDOW_H
