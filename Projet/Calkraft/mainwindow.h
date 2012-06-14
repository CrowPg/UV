#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Pile.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void initialisation();
        void connections_buttons();
        bool verif_operateur(QString);
        void refresh_ecran();

    private:
        Ui::MainWindow *ui;
        Pile *pile;
        QString ecran;

    private slots:
        void affiche_0();
        void affiche_1();
        void affiche_2();
        void affiche_3();
        void affiche_4();
        void affiche_5();
        void affiche_6();
        void affiche_7();
        void affiche_8();
        void affiche_9();
        void affiche_plus();
        void affiche_moins();
        void affiche_fois();
        void affiche_divise();
        void affiche_space();
        void press_egal();
        void press_clear();
        void press_point();
        void press_dollar();
        void press_rationnel();
        void press_radio_complexes();
        void press_radio_entiers();
        void press_radio_rationnels();
        void press_radio_reels();
};

#endif
