#ifndef ALOCACAO_HPP
#define ALOCACAO_HPP

#include <string>

struct Alocacao {
    std::string dia;
    std::string horario;
    std::string sala;

    Alocacao(std::string dia, std::string horario, std::string sala); //Método construtor para a inicialização dos atributos.
    void imprimir_dados();                                            // faz a impressão dos atributos no seguinte formato: "dia horario sala", com uma quebra de linha ao final.
};

#endif
