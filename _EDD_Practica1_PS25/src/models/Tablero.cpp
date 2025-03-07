//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/models/Tablero.h"

#include <cstdlib>
#include <iostream>

Tablero::Tablero() {
    this->inicializarTablero();
}

Tablero::~Tablero() {   // O(n²)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            delete tablero[i][j];
            tablero[i][j] = nullptr;
        }
    }
}

void Tablero::inicializarTablero() {
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            this->tablero[i][j] = new Casilla(new Ficha(this->SIMBOLO_CASILLA_LIBRE, 0), true);
        }
    }
    this->bloquearCasillas();
}

void Tablero::bloquearCasillas() {
    srand(time(nullptr));
    int contador = 0;
    int filasTablero = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnasTablero = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    while (contador < this->CASILLAS_BLOQUEADAS) {
        int i = rand() % filasTablero;
        int j = rand() % columnasTablero;
        if (this->tablero[i][j]->getIsHabilitada()) {
            this->tablero[i][j] = new Casilla(new Ficha(this->SIMBOLO_CASILLA_BLOQUEADA, 0), false);
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
            std::cout << "||" << this->tablero[i][j]->getFicha()->getLetra();
        }
        std::cout << "||" << std::endl;
    }
}

bool Tablero::isCasillaValida(const int x, const int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && this->tablero[x][y]->getIsHabilitada() && this->tablero[x][y]->getFicha()->getLetra() == this->SIMBOLO_CASILLA_LIBRE;
}

void Tablero::colocarFicha(const int x, const int y, Ficha *ficha) {
    this->tablero[x][y]->setFicha(ficha);
}

LinkedList<Casilla*> *Tablero::buscarCasillasVerticales(const int x, const int y) { // x (filas) se itera
    auto *lista = new LinkedList<Casilla*>;
    int limiteSuperior;
    int limiteInferior;
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int iterador = x;
    while (iterador > 0 && this->tablero[iterador - 1][y]->getIsHabilitada()
        && this->tablero[iterador - 1][y]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador--;

    limiteSuperior = iterador;
    iterador = x;
    while (iterador < filas - 1 && this->tablero[iterador + 1][y]->getIsHabilitada()
        && this->tablero[iterador + 1][y]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador++;

    limiteInferior = iterador;
    for (int i = limiteSuperior; i < limiteInferior + 1; i++) lista->insertar(this->tablero[i][y]);

    return lista;
}

LinkedList<Casilla *> *Tablero::buscarCasillasVerticalesSiguientes(const int x, const int y) {  // x (filas) se itera
    auto *lista = new LinkedList<Casilla*>;
    int limiteInferior;
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int iterador = x;
    while (iterador < filas - 1 && this->tablero[iterador + 1][y]->getIsHabilitada()
        && this->tablero[iterador + 1][y]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador++;

    limiteInferior = iterador;
    for (int i = x; i < limiteInferior + 1; i++) lista->insertar(this->tablero[i][y]);

    return lista;
}

LinkedList<Casilla*> *Tablero::buscarCasillasHorizontales(const int x, const int y) {   // y (columnas) se itera
    auto *lista = new LinkedList<Casilla*>;
    int limiteIzquierdo;
    int limiteDerecho;
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    int iterador = y;
    while (iterador > 0 && this->tablero[x][iterador - 1]->getIsHabilitada()
        && this->tablero[x][iterador - 1]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador--;

    limiteIzquierdo = iterador;
    iterador = y;
    while (iterador < columnas - 1 && this->tablero[x][iterador + 1]->getIsHabilitada()
        && this->tablero[x][iterador + 1]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador++;

    limiteDerecho = iterador;
    for (int i = limiteIzquierdo; i < limiteDerecho + 1; i++) lista->insertar(this->tablero[x][i]);

    return lista;
}

LinkedList<Casilla *> *Tablero::buscarCasillasHorizontalesSiguientes(const int x, const int y) {    // y (columnas) se itera
    auto *lista = new LinkedList<Casilla*>;
    int limiteDerecho;
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    int iterador = y;
    while (iterador < columnas - 1 && this->tablero[x][iterador + 1]->getIsHabilitada()
        && this->tablero[x][iterador + 1]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) iterador++;

    limiteDerecho = iterador;
    for (int i = y; i < limiteDerecho + 1; i++) lista->insertar(this->tablero[x][i]);

    return lista;
}

bool Tablero::isTableroLleno() {
    int casillasPcupadas = 0;
    int filas = sizeof(this->tablero)/sizeof(this->tablero[0]);
    int columnas = sizeof(this->tablero[0])/sizeof(this->tablero[0][0]);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (this->tablero[i][j]->getFicha()->getLetra() != this->SIMBOLO_CASILLA_LIBRE) casillasPcupadas++;
        }
    }
    return casillasPcupadas == filas * columnas;
}


