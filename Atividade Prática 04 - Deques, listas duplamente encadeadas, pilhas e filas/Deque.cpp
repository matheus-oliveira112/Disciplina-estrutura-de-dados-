#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque() : inicio(nullptr), fim(nullptr), qtd(0) {}

Deque::~Deque() {
    Node* atual = inicio;
    while (atual != nullptr) {
        Node* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

void Deque::insere_ini(const Aluno& aluno) {
    Node* novo = new Node(aluno);
    if (inicio == nullptr) {
        inicio = fim = novo;
    } else {
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }
    qtd++;
}

void Deque::insere_fim(const Aluno& aluno) {
    Node* novo = new Node(aluno);
    if (fim == nullptr) {
        inicio = fim = novo;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
    }
    qtd++;
}

Aluno Deque::remove_ini() {
    if (inicio == nullptr) {
        throw runtime_error("Erro: tentativa de remover do inicio de um deque vazio.");
    }
    Node* temp = inicio;
    Aluno removido = temp->dado;
    if (inicio == fim) {
        inicio = fim = nullptr;
    } else {
        inicio = inicio->proximo;
        inicio->anterior = nullptr;
    }
    delete temp;
    qtd--;
    return removido;
}

Aluno Deque::remove_fim() {
    if (fim == nullptr) {
        throw runtime_error("Erro: tentativa de remover do fim de um deque vazio.");
    }
    Node* temp = fim;
    Aluno removido = temp->dado;
    if (inicio == fim) {
        inicio = fim = nullptr;
    } else {
        fim = fim->anterior;
        fim->proximo = nullptr;
    }
    delete temp;
    qtd--;
    return removido;
}

int Deque::tamanho() const {
    return qtd;
}

bool Deque::vazio() const {
    return qtd == 0;
}

void Deque::imprimir() const {
    cout << "[";
    Node* atual = inicio;
    while (atual != nullptr) {
        cout << "(" << atual->dado.getNome() 
            << "," << atual->dado.getMatricula()
            << ")";
        if (atual->proximo != nullptr) cout << ", ";
        atual = atual->proximo;
    }
    cout << "]" << endl;
}

Deque Deque::operator+(const Deque& outro) const {
    Deque d3;
    Node* atual = this->inicio;
    Node* atual2 = outro.inicio;
    
    //Pega os elementos da lista d1 primeiro
    while(atual!=nullptr) {    
        d3.insere_fim(atual->dado);
        atual = atual->proximo;
    }
    
    //Pega os elementosd da lista d2
    while(atual2!=nullptr) {
        d3.insere_fim(atual2->dado);
        atual2 = atual2->proximo;
    }
   
    return d3;
}

Deque& Deque::operator+=(const Deque& outro) {
    Node* atual2 = outro.inicio;
    
    while(atual2!=nullptr) {    
        insere_fim(atual2->dado);
        atual2 = atual2->proximo;
    }
    
    return *this;
}
