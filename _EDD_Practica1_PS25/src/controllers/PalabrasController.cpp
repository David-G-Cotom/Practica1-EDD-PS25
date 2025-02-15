//
// Created by Carlos Cotom on 15/02/2025.
//

#include "../../includes/controllers/PalabrasController.h"

#include <fstream>
#include <iostream>
#include <sstream>

PalabrasController::PalabrasController() {

}

int PalabrasController::cargarPalabras(std::string &nombreArchivo, std::string palabrasExtraidas[]) {
    std::ifstream file(nombreArchivo);
    if (!file) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return 0;
    }
    int contadorPalabra = 0;
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
            if (!palabra.empty()) palabrasExtraidas[contadorPalabra++] = palabra;
        }
    }
    file.close();
    return contadorPalabra;
}

// Ordena alfabéticamente el arreglo de palabras (algoritmo de burbuja).
// Complejidad: O(n^2)
void PalabrasController::ordenarPalabras(std::string palabrasExtraidas[], int cantidadPalabras) {
    for (int i = 0; i < cantidadPalabras - 1; i++) {
        for (int j = i + 1; j < cantidadPalabras; j++) {
            if (palabrasExtraidas[i] > palabrasExtraidas[j]) {
                std::string aux = palabrasExtraidas[i];
                palabrasExtraidas[i] = palabrasExtraidas[j];
                palabrasExtraidas[j] = aux;
            }
        }
    }
}

bool PalabrasController::isPalabraValida(std::string &palabra, std::string palabraExtraidas[], int cantidadPalabras) {
    for (int i = 0; i < cantidadPalabras; i++) {
        if (palabra == palabraExtraidas[i]) return true;
    }
    return false;
}




