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
