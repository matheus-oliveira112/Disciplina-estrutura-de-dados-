#ifndef DEQUE_H
#define DEQUE_H

#include "Aluno.h"
#include <stdexcept>

class Deque {
private:
    struct Node {
        Aluno dado;
        Node* anterior;
        Node* proximo;
        Node(const Aluno& aluno) : dado(aluno), anterior(nullptr), proximo(nullptr) {}
    };

    Node* inicio;
    Node* fim;
    int qtd;

public:
    Deque();
    ~Deque();

    void insere_ini(const Aluno& aluno);
    void insere_fim(const Aluno& aluno);
    Aluno remove_ini();   // retorna o objeto removido
    Aluno remove_fim();   // retorna o objeto removido
    int tamanho() const;
    bool vazio() const;
    
    Deque operator+(const Deque& outro) const;
    Deque& operator+=(const Deque& outro);
    
    void imprimir() const;
};

#endif
