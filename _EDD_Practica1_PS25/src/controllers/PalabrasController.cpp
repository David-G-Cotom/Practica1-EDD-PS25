//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/PalabrasController.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../../includes/structs/LinkedList.h"

PalabrasController::PalabrasController() {

}

LinkedList<std::string> *PalabrasController::cargarPalabras(std::string &nombreArchivo) {
    std::ifstream file(nombreArchivo);
    if (!file) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return nullptr;
    }
    auto palabrasIniciales = new LinkedList<std::string>();
    std::string linea;
    while (std::getline(file, linea)) {
        std::stringstream stream(linea);
        std::string palabra;
        while (std::getline(stream, palabra, ',')) {
            // Se eliminan los espacios en blanco (si hubieran) de cada palabra encontrada en la linea actual
            size_t inicio = palabra.find_first_not_of(" \t");
            size_t fin = palabra.find_last_not_of(" \t");
            if (inicio != std::string::npos && fin != std::string::npos) {
                palabra = palabra.substr(inicio, fin - inicio + 1);
            }
            if (!palabra.empty()) palabrasIniciales->insertar(&palabra);
        }
    }
    file.close();
    return palabrasIniciales;
}

// Ordena alfabéticamente el arreglo de palabras (algoritmo de burbuja).
// Complejidad: O(n^2)
void PalabrasController::ordenarPalabras(LinkedList<std::string> *palabrasExtraidas) {
    for (int i = 0; i < palabrasExtraidas->getSize() - 1; i++) {
        for (int j = i + 1; j < palabrasExtraidas->getSize(); j++) {
            if (palabrasExtraidas->getElement(i)->getData() > palabrasExtraidas->getElement(j)->getData()) {
                std::string aux = palabrasExtraidas->getElement(i)->getData();
                palabrasExtraidas->getElement(i)->setData(palabrasExtraidas->getElement(j)->getData());
                palabrasExtraidas->getElement(j)->setData(aux);
            }
        }
    }
}

bool PalabrasController::isPalabraValida(std::string &palabra, LinkedList<std::string> *palabraExtraidas) {
    Node<std::string> *aux = palabraExtraidas->getRaiz();
    while (aux != nullptr) {
        if (aux->getData() == palabra) return true;
        aux = aux->getNext();
    }
    return false;
}




