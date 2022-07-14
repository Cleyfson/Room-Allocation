
#include "Alocacao.hpp"
#include <iostream>

Alocacao::Alocacao(std::string dia, std::string horario, std::string sala) {
    this->dia = dia;
    this->horario = horario;
    this->sala = sala;
}

void Alocacao::imprimir_dados() {
    std::cout << this->dia << " " << this->horario << " " << this->sala << "\n";
}