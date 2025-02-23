//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Tablero.h"

#include <cstdlib>
#include <iostream>

Tablero::Tablero() {
    this->inicializarTablero();
}

void Tablero::inicializarTablero() {
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            this->tablero[i][j] = this->SIMBOLO_CASILLA_LIBRE;
        }
    }
    this->bloquearCasillas();
}

void Tablero::bloquearCasillas() {
    int contador = 0;
    int filasTablero = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnasTablero = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    while (contador < this->CASILLAS_BLOQUEADAS) {
        int i = rand() % filasTablero;
        int j = rand() % columnasTablero;
        if (this->tablero[i][j] == this->SIMBOLO_CASILLA_LIBRE) {
            this->tablero[i][j] = this->SIMBOLO_CASILLA_BLOQUEADA;
            contador++;
        }
    }
}

void Tablero::imprimirTablero() {
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    std::cout << "     1  2  3  4  5  6  7  8  9  10 11 12 13 14 15" << std::endl;
    for (int i = 0; i < filas; i++) {
        if (i+1 < 10) std::cout << i + 1 << "  ";
        else std::cout << i + 1 << " ";

        for (int j = 0; j < columnas; j++) {
            std::cout << "||" << this->tablero[i][j];
        }
        std::cout << "||" << std::endl;
    }
}

bool Tablero::isCasillaValida(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && this->tablero[x][y] == this->SIMBOLO_CASILLA_LIBRE;
}

void Tablero::colocarLetra(int x, int y, char letra) {
    this->tablero[x][y] = letra;
}




