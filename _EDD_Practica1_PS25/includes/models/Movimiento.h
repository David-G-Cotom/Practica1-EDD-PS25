//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <string>

#include "../structs/LinkedList.h"
#include "Ficha.h"


class Movimiento {

private:
    std::string nombreJugador;
    std::string palabra;
    int puntuacionMovimiento;
    LinkedList<Ficha> *listaFichasUtilizadas;
    int contadorFichas;

public:
    Movimiento(std::string nombreJugador, std::string palabra, int puntuacionMovimiento, Ficha *fichaJugada, int contadorFichas);

    std::string getNombreJugador();
    void setNombreJugador(std::string nombreJugador);

    std::string getPalabra();
    void setPalabra(std::string palabra);

    int getPuntuacionMovimiento();
    void setPuntuacionMovimiento(int puntuacion);

    LinkedList<Ficha> *getListaFichasUtilizadas();
    void setListaFichasUtilizadas(LinkedList<Ficha> *listaFichasUtilizadas);

    int getContadorFichas();
    void setContadorFichas(int contadorFichas);

};



#endif //MOVIMIENTO_H
