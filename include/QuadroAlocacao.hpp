#ifndef QUADROALOCACAO_HPP
#define QUADROALOCACAO_HPP

#include "Disciplina.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct QuadroAlocacao {
    std::map<std::string, Disciplina> map;

    void inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala); // cria uma nova alocação para uma determinada disciplina de acordo com os parâmetros informados. Todas as disciplinas possuem códigos diferentes, ou seja, únicos.
    void imprimir_alocacao_completa();                                                                                   //imprime todo o quadro de alocação. As disciplinas devem estar ordenadas pelo código, e as alocações pelo horário da oferta.
    void remover_alocacao_disciplina(std::string codigo, std::string horario);                                           //remove a alocação em um determinado horário para a disciplina com o código informado. Lembrando que os horários de alocação são únicos em cada disciplina.
    std::vector<Disciplina> recuperar_disciplinas_mais_ofertadas();                                                      //recupera todas as disciplinas que possuem o maior número de alocações.
};

#endif