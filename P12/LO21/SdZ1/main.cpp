#include <QApplication> // Cet include vous permet d'accéder à la classe QApplication, qui est la classe de base de tout programme Qt.
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    fenetre.setFixedSize(260, 150);
    QPushButton bouton("Salut les Zéros, la forme ?", &fenetre);
    bouton.setText("Pimp mon bouton !");
    //bouton.move(30, 50);
    bouton.setGeometry(30, 50, 200, 50);
    fenetre.show();
    bouton.setToolTip("Texte d'aide");

    return app.exec();
}
