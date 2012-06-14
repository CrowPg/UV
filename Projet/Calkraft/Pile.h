#ifndef PILE_H
#define PILE_H

#include <QStack>
#include <QString>
#include <QStringList>
#include <iostream>

#include "Constante.h"
#include "Entier.h"


class Pile : public QStack<Constante*>{
    public:
        void parsage(QString s, int mode);
        void calcul(QString s, int mode);
};

#endif
