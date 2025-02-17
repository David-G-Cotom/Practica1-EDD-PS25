//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

#include "../structs/ListaEnlazada/ListaFichas.h"


class Jugador {

private:
    std::string nombre;
    int puntos;
    int movimientos;
    ListaFichas *listaFichas;

public:
    Jugador();
    Jugador(std::string nombre);

    std::string getNombre();
    void setNombre(std::string nombre);

    int getPuntos();
    void setPuntos(int puntos);

    int getMovimientos();
    void setMovimientos(int movimientos);

    ListaFichas *getListaFichas();
    void setListaFichas(ListaFichas *listaFichas);

};



#endif //JUGADOR_H
