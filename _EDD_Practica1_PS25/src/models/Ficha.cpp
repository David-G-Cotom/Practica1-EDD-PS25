//
// Created by Carlos Cotom on 14/02/2025.
//

#include "../../includes/models/Ficha.h"

Ficha::Ficha(char letra, int valor) {
    this->letra = letra;
    this->valor = valor;
}

char Ficha::getLetra() {
    return this->letra;
}

void Ficha::setLetra(char letra) {
    this->letra = letra;
}

int Ficha::getValor() {
    return this->valor;
}

void Ficha::setValor(int valor) {
    this->valor = valor;
}


