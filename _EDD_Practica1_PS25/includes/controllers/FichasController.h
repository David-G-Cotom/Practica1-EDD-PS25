//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef FICHASCONTROLLER_H
#define FICHASCONTROLLER_H

#include <string>

#include "../models/Jugador.h"
#include "../structs/ListaEnlazada/ListaFichas.h"


class FichasController {

    public:
    FichasController();

    ListaFichas *crearFichasIniciales(std::string palabrasIniciales[], int cantidadPalabras);

    void distribuirFichas(ListaFichas *listaGeneralFichas, Jugador jugadores[], int cantidadJugadores);

};



#endif //FICHASCONTROLLER_H
