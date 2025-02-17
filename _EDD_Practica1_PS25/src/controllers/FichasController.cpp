//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/FichasController.h"

FichasController::FichasController() {

}

// Crea la lista de fichas inicial a partir de las letras de las palabras cargadas
// A cada letra se le asigna un valor aleatorio entre 1 y 10.
LinkedList<Ficha> *FichasController::crearFichasIniciales(LinkedList<std::string> *palabrasIniciales) {
    auto *listaGeneralFichas = new LinkedList<Ficha>();
    for (int i = 0; i < palabrasIniciales->getSize(); i++) {
        for (char caracter: palabrasIniciales->getElement(i)->getData()) {
            if (isalpha(caracter)) {
                char letra = toupper(caracter);
                int valor = rand() % 10 + 1;
                auto *nuevaFicha = new Ficha(letra, valor);
                listaGeneralFichas->insertar(nuevaFicha);
            }
        }
    }
    return listaGeneralFichas;
}

// Reparte todas las fichas a cada jugador de manera aleatoria.
void FichasController::distribuirFichas(LinkedList<Ficha> *listaGeneralFichas, LinkedList<Jugador> *jugadores) {
    // Cuenta la cantidad de fichas iniciales
    int cantidadFichas = listaGeneralFichas->getSize();
    int cantidadFichasPorJugador = cantidadFichas / jugadores->getSize();
    for (int i = 0; i < jugadores->getSize(); i++) {
        for (int j = 0; j < cantidadFichasPorJugador; j++) {
            if (cantidadFichas == 0) break;

            int index = rand() % cantidadFichas;
            Node<Ficha> *fichaSeleccionada = listaGeneralFichas->eliminarFicha(index);
            jugadores->getElement(i)->getData()->insertarFichaOrdenada(fichaSeleccionada);
            cantidadFichas--;
        }
    }
}
