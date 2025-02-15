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
            this->tablero[i][j] = ' ';
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
        if (this->tablero[i][j] == ' ') {
            this->tablero[i][j] = '-';
            contador++;
        }
    }
}

void Tablero::imprimirTablero() {
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << "|" << this->tablero[i][j];
        }
        std::cout << "|" << std::endl;
    }
}


