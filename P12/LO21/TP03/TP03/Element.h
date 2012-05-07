#ifndef ELEMENT_H
#define ELEMENT_H

#include <QObject>
#include <QString>
#include <QTextStream>
class Element : public QObject {
    Q_OBJECT // Macro qui permet à une étape de compilation dédiée à Qt d'ajouter du code permettant d'interpréter les signaux, les slots ... A ajouter dès qu'on fait une classe qui hérite de QObject.
public:
    Element(QObject * parent = 0, QString name = "");
~Element(); };
#endif // ELEMENT_H
