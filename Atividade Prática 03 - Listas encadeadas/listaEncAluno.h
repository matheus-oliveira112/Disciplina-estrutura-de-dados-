#ifndef LISTA_ENC_ALUNO_H
#define LISTA_ENC_ALUNO_H

#include "aluno.h"
#include <iostream>
using namespace std;

class ListaEncadeadaAluno {
protected:
    class No {
    public:
        No(const Aluno& a) : aluno(a), proximo(nullptr) {}
        Aluno aluno;
        No* proximo;
    };

    No* inicio;
    int qtdElementos;

public:
    ListaEncadeadaAluno();
    virtual ~ListaEncadeadaAluno();

    bool inserirInicio(const Aluno& a);
    bool inserirFim(const Aluno& a);
    bool inserir(const Aluno& a, int pos);
    bool remover(int pos);

    int buscarMatricula(int matricula) const;
    Aluno* getAluno(int pos) const;
    int getQtdElementos() const;
    void exibir() const;

    // ===== Exercício 1 =====
    // Operador de comparação entre duas listas
    bool operator==(const ListaEncadeadaAluno& outra) const;

    // ===== Exercício extra =====
    // Inverter a ordem da lista
    void inverter();
};

#endif
