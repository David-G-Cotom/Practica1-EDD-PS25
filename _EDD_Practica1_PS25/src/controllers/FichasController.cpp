//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/FichasController.h"

#include <iostream>
#include <ostream>

FichasController::FichasController() = default;

// Crea la lista de fichas inicial a partir de las letras de las palabras cargadas
// A cada letra se le asigna un valor aleatorio entre 1 y 10.
LinkedList<Ficha> *FichasController::crearFichasIniciales(LinkedList<std::string> *palabrasIniciales) {
    srand(time(NULL));
    std::cout << "Creando Fichas para el Juego" << std::endl;
    auto *listaGeneralFichas = new LinkedList<Ficha>();
    for (int i = 0; i < palabrasIniciales->getSize(); i++) {
        for (char caracter: *palabrasIniciales->getElement(i)->getData()) {
            if (isalpha(caracter)) {
                char letra = toupper(caracter);
                int valor = rand() % 10 + 1;
                auto *nuevaFicha = new Ficha(letra, valor);
                listaGeneralFichas->insertar(nuevaFicha);
            }
        }
    }
    std::cout << "Fichas Creadas Exitosamente" << std::endl;
    return listaGeneralFichas;
}

// Reparte todas las fichas a cada jugador de manera aleatoria.
void FichasController::distribuirFichas(LinkedList<Ficha> *listaGeneralFichas, LinkedList<Jugador> *jugadores) {
    srand(time(NULL));
    int cantidadFichas = listaGeneralFichas->getSize();
    std::cout << "Cantidad Fichas: " << cantidadFichas << std::endl;
    int cantidadJugadores = jugadores->getSize();
    int fichasFaltantes = cantidadFichas % cantidadJugadores;
    if (fichasFaltantes != 0) {
        fichasFaltantes = cantidadJugadores - fichasFaltantes;
        for (int i = 0; i < fichasFaltantes; i++) {
            int valorASCII = (rand() % 26 + 1) + 64;    //LETRAS MAYUSCULAS
            char letra = valorASCII;
            int valor = rand() % 10 + 1;
            auto *nuevaFicha = new Ficha(letra, valor);
            listaGeneralFichas->insertar(nuevaFicha);
        }
        std::cout << "Se crearon " << fichasFaltantes << " fichas faltantes" << std::endl;
    }
    std::cout << "Distribuyendo las Fichas a los Jugadores" << std::endl;
    cantidadFichas = listaGeneralFichas->getSize();
    int cantidadFichasPorJugador = cantidadFichas / cantidadJugadores;
    for (int i = 0; i < jugadores->getSize(); i++) {
        for (int j = 0; j < cantidadFichasPorJugador; j++) {
            if (cantidadFichas == 0) break;

            int index = rand() % cantidadFichas;
            Node<Ficha> *fichaSeleccionada = listaGeneralFichas->eliminarFicha(index);
            jugadores->getElement(i)->getData()->insertarFichaOrdenada(fichaSeleccionada);
            cantidadFichas--;
        }
    }
    std::cout << "Fichas Distribuidas Exitosamente" << std::endl;
}
