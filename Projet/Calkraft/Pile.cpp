#include "Pile.h"
#include "Entier.h"
#include "mainwindow.h"

void Pile::parsage(QString s, int mode) {
    QStringList list = s.split(" ");
    foreach (const QString &val, list) {
        if(val != "+" && val != "-" && val != "*" && val != "/" && val != " ") {

            if(mode == 1) {
                std::cout << "\n"<< val.toStdString() << " C'est un entier";
                push(new Entier(val.toInt()));
            } else if(mode == 2) {
                std::cout << "\n"<< val.toStdString() << " C'est un complexe";
                if (val.contains('$')) {
                    double a = val.mid(0, val.indexOf('$')).toDouble();
                    double b = val.mid(val.indexOf(('$'))+1).toDouble();
                    push(new Complexe(a, b));
                }
                else {
                    push(new Complexe(val.toDouble(), 0));
                }
            } else if(mode == 3) {
                if (val.contains('/')) {
                    std::cout << "\n"<< val.toStdString() << " C'est un rationnel";
                    double a = val.mid(0, val.indexOf('/')).toDouble();
                    double b = val.mid(val.indexOf(('/'))+1).toDouble();
                    push(new Rationnel(a, b));
                } else {
                    push(new Rationnel(val.toDouble(), 1));
                }
            } else if(mode == 4) {
                std::cout << "\n"<< val.toStdString() << " C'est un reel";
                push(new Reel(val.toDouble()));
            }
        }
        else {
            calcul(val, mode);
        }
    }
}



void Pile::calcul(QString operateur, int mode) {
    if(!isEmpty()) {

        //Entier
        if(mode == 1) {
            Entier* val1 = (Entier*)pop();
            if(!isEmpty()) {
                Entier* val2 = (Entier*)pop();
                Entier*newval= new Entier(0);
                if(operateur == "+")
                   *newval = *val1+*val2;
                else if (operateur == "-")
                    *newval = *val2-*val1;
                else if (operateur == "/")
                    *newval = *val2/ *val1;
                else //(operateur == "*")
                    *newval = *val1* *val2;
                push(newval);
            } else {
                push(val1);
            }
        }
        //Complexe
        else if(mode == 2) {
            Complexe* val1 = (Complexe*)pop();
            if(!isEmpty()) {
                Complexe* val2 = (Complexe*)pop();
                Complexe*newval= new Complexe(0, 0);
                if(operateur == "+")
                   *newval = *val1+*val2;
                else if (operateur == "-")
                    *newval = *val2-*val1;
                else if (operateur == "/")
                    *newval = *val2/ *val1;
                else //(operateur == "*")
                    *newval = *val1* *val2;
                push(newval);
            } else {
                push(val1);
            }
        }
        //Rationnels
        else if(mode == 3) {
            Rationnel* val1 = (Rationnel*)pop();
            if(!isEmpty()) {
                Rationnel* val2 = (Rationnel*)pop();
                Rationnel* newval= new Rationnel(0, 0);
                if(operateur == "+")
                   *newval = *val1+*val2;
                else if (operateur == "-")
                    *newval = *val2-*val1;
                else if (operateur == "/")
                    *newval = *val2/ *val1;
                else //(operateur == "*")
                    *newval = *val1* *val2;
                push(newval);
            } else {
                push(val1);
            }
        }
        //Reels
        else if(mode == 4) {
            Reel* val1 = (Reel*)pop();
            if(!isEmpty()) {
                Reel* val2 = (Reel*)pop();
                Reel*newval= new Reel(0);
                if(operateur == "+")
                   *newval = *val1+*val2;
                else if (operateur == "-")
                    *newval = *val2-*val1;
                else if (operateur == "/")
                    *newval = *val2/ *val1;
                else //(operateur == "*")
                    *newval = *val1* *val2;
                std::cout << newval->getVal();
                push(newval);
            } else {
                push(val1);
            }
        }
    }
}

