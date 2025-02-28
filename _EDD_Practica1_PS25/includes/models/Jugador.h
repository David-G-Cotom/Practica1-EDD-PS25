//
// Created by Carlos Cotom on 15/02/2025.
//

#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

#include "../structs/LinkedList.h"
#include "Ficha.h"


class Jugador {

private:
    std::string nombre;
    int puntos;
    int movimientos;
    LinkedList<Ficha> *listaFichas;

public:
    Jugador(std::string nombre);

    ~Jugador();

    std::string getNombre();
    void setNombre(std::string nombre);

    int getPuntos();
    void setPuntos(int puntos);

    int getMovimientos();
    void setMovimientos(int movimientos);

    LinkedList<Ficha> *getListaFichas();
    void setListaFichas(LinkedList<Ficha> *listaFichas);

    void insertarFichaOrdenada(Node<Ficha> *ficha);

    void imprimirFichas();

    Ficha *usarFichas(char letra);

};



#endif //JUGADOR_H
