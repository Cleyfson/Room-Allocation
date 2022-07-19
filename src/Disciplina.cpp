#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"
#include "algorithm"
#include <iostream>

Disciplina::Disciplina(std::string codigo, std::string nome) // método construtor para a inicialização dos atributos.
{
    this->codigo = codigo;
    this->nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala) // cria uma nova alocação para a disciplina a partir dos dados informados e insere na coleção.
{
    myList.push_front(Alocacao(dia, horario, sala));
}

void Disciplina::remover_alocacao(std::string horario) // remove uma alocação da coleção. Para facilitar, vamos assumir que existe apenas uma única alocação em cada horário.
{
    for (auto iter = myList.begin(); iter != myList.end(); iter++) {
        if ((*iter).horario == horario)
            iter = myList.erase(iter);
    }
}

void Disciplina::imprimir_alocacao() // imprime todas as alocações para a disciplina. Cada alocação deve ser impressa em uma linha separada e seguindo o formato "codigo nome dia horario sala". Além disso, a alocação deve ser impressa ordenada de acordo com o horário.
{
    for (auto iter = myList.begin(); iter != myList.end(); iter++) {
        std::cout << this->codigo << " " << this->nome << " ";
        (*iter).imprimir_dados();
    }
}