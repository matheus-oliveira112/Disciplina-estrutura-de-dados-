#include <iostream>
#include <cassert>
#include "ListaEncadeada.h"
#include "Aluno.h"
using namespace std;

int main() {
     // Teste 1: lista vazia
    {
        ListaEncadeada<int> lista;
        int contador = 0;
        for (auto x : lista) contador++;
        assert(contador == 0); // não deve iterar nada
    }

    // Teste 2: inserção e iteração simples
    {
        ListaEncadeada<int> lista;
        lista.inserirFim(1);
        lista.inserirFim(2);
        lista.inserirFim(3);

        int esperado[] = {1, 2, 3};
        int i = 0;
        for (auto x : lista) {
            assert(x == esperado[i]);
            i++;
        }
        assert(i == 3);
    }

    // Teste 3: modificação por referência
    {
        ListaEncadeada<int> lista;
        lista.inserirFim(5);
        lista.inserirFim(10);

        for (auto& x : lista) {
            x *= 2; // dobra os valores
        }

        int esperado[] = {10, 20};
        int i = 0;
        for (auto x : lista) {
            assert(x == esperado[i]);
            i++;
        }
        assert(i == 2);
    }

    // Teste 4: tipos diferentes (std::string)
    {
        ListaEncadeada<string> lista;
        lista.inserirFim("A");
        lista.inserirFim("B");
        lista.inserirFim("C");

        string concatenado;
        for (auto& s : lista) concatenado += s;

        assert(concatenado == "ABC");
    }

    // Teste 4: tipos diferentes (aluno)
    {
        ListaEncadeada<Aluno> listaAlunos;
        listaAlunos.inserirFim(Aluno(1, "Ana"));
        listaAlunos.inserirFim(Aluno(2, "Bruno"));
        listaAlunos.inserirFim(Aluno(3, "Carlos"));
        for (auto aluno : listaAlunos) {
            cout << aluno << endl;
        }
        
        /*
         * Nao tem assert, mas a saida deve ser:
         * Aluno(Matricula: 1, Nome: Ana)
         * Aluno(Matricula: 2, Nome: Bruno)
         * Aluno(Matricula: 3, Nome: Carlos)
         */
    }

}
