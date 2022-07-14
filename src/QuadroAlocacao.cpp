#include "QuadroAlocacao.hpp"
#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "algorithm"
#include <iostream>

void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala) // cria uma nova alocação para uma determinada disciplina de acordo com os parâmetros informados. Todas as disciplinas possuem códigos diferentes, ou seja, únicos.
{
    if (map.count(codigo)) {
        auto it = map.find(codigo);
        auto iter = (*it).second.myList.begin();
        for (; iter != (*it).second.myList.end(); iter++) {
            if (horario < (*iter).horario) {
                (*it).second.myList.insert(iter, Alocacao(dia, horario, sala));
                return;
            }
        }
        (*it).second.myList.push_back(Alocacao(dia, horario, sala));

    } else {
        Disciplina temp(codigo, nome);
        temp.inserir_alocacao(dia, horario, sala);
        map.insert(std::make_pair(codigo, temp));
    }
}

void QuadroAlocacao::imprimir_alocacao_completa() //imprime todo o quadro de alocação. As disciplinas devem estar ordenadas pelo código, e as alocações pelo horário da oferta.
{
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        (*iter).second.imprimir_alocacao();
    }
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas() //recupera todas as disciplinas que possuem o maior número de alocações.
{
    int long unsigned size = 0;
    std::string previous_key;
    std::string key;
    std::vector<Disciplina> result;

    for (auto iter = map.begin(); iter != map.end(); iter++) {
        key = (*iter).first;
        if ((*iter).second.myList.size() > size) {
            size = (*iter).second.myList.size();
        }
    }

    for (auto iter = map.begin(); iter != map.end(); iter++) {
        key = (*iter).first;
        if ((*iter).second.myList.size() == size && (*iter).second.codigo != previous_key) {
            auto it = map.equal_range(key);

            for (auto i = it.first; i != it.second; ++i)
                result.push_back(i->second);

            previous_key = (*iter).second.codigo;
        }
    }

    return result;
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario) //remove a alocação em um determinado horário para a disciplina com o código informado. Lembrando que os horários de alocação são únicos em cada disciplina.
{
    //auto it = map.equal_range(codigo, horario);
    //auto is = (*it)
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        for (auto it = (*iter).second.myList.begin(); it != (*iter).second.myList.end(); it++) {
            if ((*iter).first == codigo && (*it).horario == horario) {
                (*iter).second.myList.erase(it);
                break;
            }
        }
    }
}
