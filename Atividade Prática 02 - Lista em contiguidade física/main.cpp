#include <iostream>
#include "listaContigAluno.h"

int main() {
    // 1. Cria a lista com capacidade 5
    ListaContigAluno lista(5);

    std::cout << "--- TESTANDO INSERIR NO FIM ---" << std::endl;
    lista.inserirFim(Aluno(10, "Joao"));
    lista.inserirFim(Aluno(20, "Maria"));
    lista.exibir();

    // 2. Testa a nova função de inserção em uma posição específica
    std::cout << "\n--- TESTANDO INSERIR NA POSICAO 1 ---" << std::endl;
    bool sucessoInserir = lista.inserir(Aluno(30, "Carlos"), 1);
    if (sucessoInserir) {
        std::cout << "Aluno inserido com sucesso na posicao 1." << std::endl;
    } else {
        std::cout << "Erro ao inserir aluno na posicao 1." << std::endl;
    }
    lista.exibir();

    // 3. Testa a nova função de busca por nome
    std::cout << "\n--- TESTANDO BUSCAR POR NOME ---" << std::endl;
    std::string nomeBusca = "Maria";
    int posNome = lista.buscarNome(nomeBusca);
    if (posNome != -1) {
        std::cout << "Aluno '" << nomeBusca << "' encontrado na posicao " << posNome << "." << std::endl;
    } else {
        std::cout << "Aluno '" << nomeBusca << "' nao encontrado." << std::endl;
    }

    // 4. Testa a nova função de remoção por matrícula
    std::cout << "\n--- TESTANDO REMOVER POR MATRICULA ---" << std::endl;
    int matriculaRemover = 30; // Matrícula de Carlos
    bool sucessoRemover = lista.removerPorMatricula(matriculaRemover);
    if (sucessoRemover) {
        std::cout << "Aluno com matricula " << matriculaRemover << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Erro ao remover aluno com matricula " << matriculaRemover << "." << std::endl;
    }
    lista.exibir();

    // 5. Testa a remoção de uma matrícula que não existe
    std::cout << "\n--- TESTANDO REMOVER MATRICULA INEXISTENTE ---" << std::endl;
    int matriculaInexistente = 99;
    sucessoRemover = lista.removerPorMatricula(matriculaInexistente);
    if (!sucessoRemover) {
        std::cout << "Aluno com matricula " << matriculaInexistente << " nao encontrado. Remocao falhou." << std::endl;
    }
    
    return 0;
}
