//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
#include "../structs/LinkedList.h"


class Tablero {

private:
    static const int SIZE = 15;    //El tablero sera de 15*15
    const int CASILLAS_BLOQUEADAS = 10;
    const char SIMBOLO_CASILLA_LIBRE = ' ';
    const char SIMBOLO_CASILLA_BLOQUEADA = '#';

    Casilla *tablero[SIZE][SIZE];

    void inicializarTablero();
    void bloquearCasillas();

public:
    Tablero();

    void imprimirTablero();

    bool isCasillaValida(int x, int y);

    void colocarFicha(int x, int y, Ficha *ficha);

    LinkedList<Casilla*> *buscarCasillasVerticales(int x, int y);

    LinkedList<Casilla*> *buscarCasillasVerticalesSiguientes(int x, int y);

    LinkedList<Casilla*> *buscarCasillasHorizontales(int x, int y);

    LinkedList<Casilla*> *buscarCasillasHorizontalesSiguientes(int x, int y);

    bool isTableroLleno();

};



#endif //TABLERO_H
