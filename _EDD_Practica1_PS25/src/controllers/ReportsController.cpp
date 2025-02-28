//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/ReportsController.h"

#include <iostream>
#include <ostream>

ReportsController::ReportsController() = default;

void ReportsController::historialPalabrasJugadas(Stack<std::string> *palabrasEencontradas) {
    Node<std::string> *aux = palabrasEencontradas->getRaiz();
    std::cout << "--- Historial de Palabras Jugadas ---" << std::endl;
    while (aux) {
        std::cout << aux->getData() << std::endl;
        aux = aux->getNext();
    }
}

void ReportsController::historialPalabrasNoEncontradas(LinkedList<std::string> *palabrasNoEncontradas) {
    Node<std::string> *aux = palabrasNoEncontradas->getRaiz();
    std::cout << "--- Historial de Palabras No Encontradas ---" << std::endl;
    while (aux) {
        std::cout << aux->getData() << std::endl;
        aux = aux->getNext();
    }
}

// Ordena alfabéticamente el arreglo de palabras (algoritmo de burbuja).
// Complejidad: O(n^2)
void ReportsController::jugadoresOrdenadoPuntaje(LinkedList<Jugador> *jugadores) {
    LinkedList<Jugador> *aux = jugadores;
    std::cout << "--- Lista de Jugadores Ordenada por Puntaje ---" << std::endl;
    for (int i = 0; i < jugadores->getSize() - 1; i++) {
        for (int j = i + 1; j < jugadores->getSize(); j++) {
            if (aux->getElement(i)->getData()->getPuntos() > aux->getElement(j)->getData()->getPuntos()) {
                Jugador *jugadorAux = aux->getElement(i)->getData();
                aux->getElement(i)->setData(aux->getElement(j)->getData());
                aux->getElement(j)->setData(jugadorAux);
            }
        }
    }
    Node<Jugador> *nodoAux = aux->getRaiz();
    int i = 1;
    while (nodoAux) {
        std::cout << i << ". " << nodoAux->getData()->getNombre() << " -> " << nodoAux->getData()->getPuntos() << " puntos" << std::endl;
        nodoAux = nodoAux->getNext();
        i++;
    }
}

// Ordena alfabéticamente el arreglo de palabras (algoritmo de burbuja).
// Complejidad: O(n^2)
void ReportsController::jugadoresOrdenadoNombre(LinkedList<Jugador> *jugadores) {
    LinkedList<Jugador> *aux = jugadores;
    std::cout << "--- Lista de Jugadores Ordenada por Nombre ---" << std::endl;
    for (int i = 0; i < jugadores->getSize() - 1; i++) {
        for (int j = i + 1; j < jugadores->getSize(); j++) {
            if (aux->getElement(i)->getData()->getNombre() > aux->getElement(j)->getData()->getNombre()) {
                Jugador *jugadorAux = aux->getElement(i)->getData();
                aux->getElement(i)->setData(aux->getElement(j)->getData());
                aux->getElement(j)->setData(jugadorAux);
            }
        }
    }
    Node<Jugador> *nodoAux = aux->getRaiz();
    int i = 1;
    while (nodoAux) {
        std::cout << i << ". " << nodoAux->getData()->getNombre() << std::endl;
        nodoAux = nodoAux->getNext();
        i++;
    }
}

void ReportsController::tiempoPromedioTurno(long tiempoTotalTurnos, int totalTurnos) {
    std::cout << "--- Tiempo Promedio de Cada Turnos ---" << std::endl;
    std::cout << (totalTurnos > 0 ? tiempoTotalTurnos/totalTurnos : 0) << " ms" << std::endl;
}

void ReportsController::movimientoPorJugador(LinkedList<Jugador> *jugadores) {
    Node<Jugador> *aux = jugadores->getRaiz();
    std::cout << "--- Cantidad de Movimientos por Jugador ---";
    while (aux) {
        std::cout << aux->getData()->getNombre() << " -> " << aux->getData()->getMovimientos() << " movimientos" << std::endl;
        aux = aux->getNext();
    }
}
