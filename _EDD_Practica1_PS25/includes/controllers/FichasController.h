//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef FICHASCONTROLLER_H
#define FICHASCONTROLLER_H

#include <string>

#include "../models/Jugador.h"


class FichasController {

public:
    FichasController();

    ~FichasController();

    LinkedList<Ficha> *crearFichasIniciales(LinkedList<std::string> *palabrasIniciales);

    void distribuirFichas(LinkedList<Ficha> *listaGeneralFichas, LinkedList<Jugador> *jugadores);

};



#endif //FICHASCONTROLLER_H
