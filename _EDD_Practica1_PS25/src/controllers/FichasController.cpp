//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/FichasController.h"

FichasController::FichasController() {

}

// Crea la lista de fichas inicial a partir de las letras de las palabras cargadas
// A cada letra se le asigna un valor aleatorio entre 1 y 10.
ListaFichas *FichasController::crearFichasIniciales(std::string palabrasIniciales[], int cantidadPalabras) {
    auto *listaGeneralFichas = new ListaFichas();
    for (int i = 0; i < cantidadPalabras; i++) {
        for (char caracter: palabrasIniciales[i]) {
            if (isalpha(caracter)) {
                char letra = toupper(caracter);
                int valor = rand() % 10 + 1;
                auto *nuevaFicha = new Ficha(letra, valor);
                listaGeneralFichas->insertarFicha(nuevaFicha);
            }
        }
    }
    return listaGeneralFichas;
}

// Reparte todas las fichas a cada jugador de manera aleatoria.
void FichasController::distribuirFichas(ListaFichas *listaGeneralFichas, Jugador jugadores[], int cantidadJugadores) {
    // Cuenta la cantidad de fichas iniciales
    int cantidadFichas = 0;
    NodoLista *aux = listaGeneralFichas->getInicio();
    while (aux != nullptr) {
        cantidadFichas++;
        aux = aux->getSiguiente();
    }
    int cantidadFichasPorJugador = cantidadFichas / cantidadJugadores;
    for (int i = 0; i < cantidadJugadores; i++) {
        for (int j = 0; j < cantidadFichasPorJugador; j++) {
            if (cantidadFichas == 0) break;

            int index = rand() % cantidadFichas;
            NodoLista *fichaSeleccionada = listaGeneralFichas->eliminarFicha(index);
            jugadores[i].getListaFichas()->insertarFichaOrdenada(fichaSeleccionada);
            cantidadFichas--;
        }
    }
}
