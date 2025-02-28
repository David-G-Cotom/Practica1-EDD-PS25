//
// Created by Carlos Cotom on 23/02/2025.
//

#ifndef CASILLA_H
#define CASILLA_H

#include "Ficha.h"


class Casilla {

private:
    Ficha *ficha;
    bool isHabilitada;

public:
    Casilla(Ficha *ficha, bool isHabilitada);

    Ficha *getFicha();
    void setFicha(Ficha *ficha);

    bool getIsHabilitada();
    void setIsHabilitada(bool isHabilitada);

};



#endif //CASILLA_H
