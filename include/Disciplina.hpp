#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include "Alocacao.hpp"
#include <list>
#include <string>

struct Disciplina {
    std::string codigo;
    std::string nome;
    std::list<Alocacao> myList;

    Disciplina(std::string codigo, std::string nome);                              //método construtor para a inicialização dos atributos.
    void inserir_alocacao(std::string dia, std::string horario, std::string sala); //cria uma nova alocação para a disciplina a partir dos dados informados e insere na coleção.
    void remover_alocacao(std::string horario);                                    //remove uma alocação da coleção. Para facilitar, vamos assumir que existe apenas uma única alocação em cada horário.
    void imprimir_alocacao();                                                      //imprime todas as alocações para a disciplina. Cada alocação deve ser impressa em uma linha separada e seguindo o formato "codigo nome dia horario sala". Além disso, a alocação deve ser impressa ordenada de acordo com o horário.
};

#endif
