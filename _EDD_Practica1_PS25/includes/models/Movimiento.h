//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <string>

#include "../structs/ListaEnlazada/ListaFichas.h"


class Movimiento {

private:
    std::string nombreJugador;
    std::string palabra;
    int puntuacionMovimiento;
    ListaFichas *listaFichasUtilizadas;
    int contadorFichas;

public:
    Movimiento();

    std::string getNombreJugador();
    void setNombreJugador(std::string nombreJugador);

    std::string getPalabra();
    void setPalabra(std::string palabra);

    int getPuntuacionMovimiento();
    void setPuntuacionMovimiento(int puntuacion);

    ListaFichas *getListaFichasUtilizadas();
    void setListaFichasUtilizadas(ListaFichas *listaFichasUtilizadas);

    int getContadorFichas();
    void setContadorFichas(int contadorFichas);

};



#endif //MOVIMIENTO_H
