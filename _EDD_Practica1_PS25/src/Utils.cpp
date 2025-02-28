//
// Created by Carlos Cotom on 22/02/2025.
//

#include "../includes/Utils.h"

#include <iostream>
#include <sstream>

void Utils::verificarEntradaNumerica(int &valorAsignado, const std::string textoMostrar) {
    std::string entrada;
    while (true) {
        try {
            std::cout << textoMostrar;
            std::getline(std::cin, entrada);
            std::stringstream ss(entrada);
            if (!(ss >> valorAsignado) || !(ss.eof())) {
                throw std::runtime_error("Debe Ingresar un Valor Numerico");
            }
            break;
        } catch (const std::exception &e) {
            std::cout <<">> Error!!!: " << e.what() << std::endl;
        }
    }
}

bool Utils::isEquals(const std::string &cadena1, const std::string &cadena2) {
    int longitud1 = cadena1.length();
    int longitud2 = cadena2.length();

    if (longitud1 != longitud2) return false;

    for (int i = 0; i < longitud1; i++) {
        if (std::tolower(static_cast<unsigned char>(cadena1[i]))
            != std::tolower(static_cast<unsigned char>(cadena2[i]))) {
            return false;
            }
    }
    return true;
}
