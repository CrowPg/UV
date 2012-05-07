#include "Element.h"


extern QTextStream cout; //extern : quand l'objet est déjà créé et qu'on ne veut pas le recréer, ici c'est le cas parce qu'on a un stream, et un stream ça ne se duplique pas
Element::Element(QObject * parent, QString name):
    QObject(parent) // l'arbre se fait grâce à ça, tout seul (L'élément est ajouté à la liste des enfants et le parent est ajouté à la liste des parents de l'élément)
{
    setObjectName(name);
    cout << "Creation de l'element " << name << endl;
}

Element::~Element(){
    cout << "Liberer l'element " << this->objectName() << endl;
}
