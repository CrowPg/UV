#include <QTextStream>
#include <cstdio>
#include "element.h"
QTextStream cout(stdout, QIODevice::WriteOnly);
void createGuiTree() {
    cout<<"Debut de la fonction"<<endl;
    // allocation statique, la memoire sera liberee a la fin
    Element guiTree(0, "Interface");
    // allocation dynamique des sous structures
    Element * mainWidget = new Element(&guiTree, "MainWidget");
    Element * menuBar = new Element(mainWidget, "MenuBar");
    Element * fileMenu = new Element(menuBar, "File");
    new Element(fileMenu, "QuitItem");
    new Element(menuBar, "Edit");
    new Element(menuBar, "Help");
    new Element(mainWidget, "StatusBar");
    cout<<"Afficher les objets"<<endl;
    guiTree.dumpObjectTree();
    cout<<"Fin de la fonction"<<endl;
}
int main(int argc, char *argv[]) {
    createGuiTree();
    return 0;
}
