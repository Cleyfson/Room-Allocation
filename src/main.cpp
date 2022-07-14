// NÃO ALTERE ESSA LINHA
#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"
#include "avaliacao_basica_alocacao.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    QuadroAlocacao quadro_alocacao;
    std::vector<Disciplina> vetor;
    std::string codigo;
    std::string nome;
    std::string dia;
    std::string horario;
    std::string sala;
    char opcao;

    while (std::cin >> opcao) {
        switch (opcao) {
        case 'a':
            std::cin >> codigo >> nome >> dia >> horario >> sala;
            quadro_alocacao.inserir_alocacao(codigo, nome, dia, horario, sala);
            break;

        case 'm':
            vetor = quadro_alocacao.recuperar_disciplinas_mais_ofertadas();
            for (auto i = vetor.begin(); i != vetor.end(); i++) {
                (*i).imprimir_alocacao();
            }
            break;

        case 'r':
            std::cin >> codigo >> horario;
            quadro_alocacao.remover_alocacao_disciplina(codigo, horario);
            break;

        case 'p':
            quadro_alocacao.imprimir_alocacao_completa();
            break;

        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}
