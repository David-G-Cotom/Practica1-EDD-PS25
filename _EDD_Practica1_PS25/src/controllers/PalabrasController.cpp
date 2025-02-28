//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/PalabrasController.h"
#include "../../includes/Utils.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>


PalabrasController::PalabrasController() = default;

PalabrasController::~PalabrasController() = default;

LinkedList<std::string> *PalabrasController::cargarPalabras(std::string &nombreArchivo) {
    std::ifstream file(nombreArchivo);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo en la ruta: " << nombreArchivo << std::endl;
        return nullptr;
    }
    std::cout << "Archivo Cargado Correctamente" << std::endl;
    auto palabrasIniciales = new LinkedList<std::string>();
    std::string linea;
    while (std::getline(file, linea)) {
        std::stringstream stream(linea);
        std::string palabra;
        while (std::getline(stream, palabra, ',')) {
            // Se eliminan los espacios en blanco (si hubieran) de cada palabra encontrada en la linea actual
            size_t inicio = palabra.find_first_not_of(" \t\r");
            size_t fin = palabra.find_last_not_of(" \t\r");
            if (inicio != std::string::npos && fin != std::string::npos) {
                palabra = palabra.substr(inicio, fin - inicio + 1);
            }
            if (!palabra.empty()) palabrasIniciales->insertar(palabra);
        }
    }
    file.close();
    std::cout << "Archivo Leido Correctamente" << std::endl;
    return palabrasIniciales;
}

// Ordena alfabéticamente el arreglo de palabras (algoritmo de burbuja).
// Complejidad: O(n^2)
void PalabrasController::ordenarPalabras(LinkedList<std::string> *palabrasExtraidas) {
    for (int i = 0; i < palabrasExtraidas->getSize() - 1; i++) {
        for (int j = i + 1; j < palabrasExtraidas->getSize(); j++) {
            if (palabrasExtraidas->getElement(i)->getValue() > palabrasExtraidas->getElement(j)->getValue()) {
                std::string aux = palabrasExtraidas->getElement(i)->getValue();
                palabrasExtraidas->getElement(i)->setValue(palabrasExtraidas->getElement(j)->getValue());
                palabrasExtraidas->getElement(j)->setValue(aux);
            }
        }
    }
    std::cout << "Palabras Registradas:" << std::endl;
    for (int i = 0; i < palabrasExtraidas->getSize(); ++i) {
        std::cout << palabrasExtraidas->getElement(i)->getValue() << " - ";
    }
    std::cout << std::endl;
}

bool PalabrasController::isPalabraValida(std::string &palabra, LinkedList<std::string> *palabraExtraidas) {
    Node<std::string> *aux = palabraExtraidas->getRaiz();
    while (aux != nullptr) {
        if (Utils::isEquals(aux->getValue(), palabra)) {
            std::cout << "Palabra " << palabra << " Encontrada!!!" << std::endl;
            palabraExtraidas->eliminar(aux->getData());
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}




