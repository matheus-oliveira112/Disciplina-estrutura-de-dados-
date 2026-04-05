#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>
using namespace std;

template <typename T>
class ListaEncadeada {
private:
    class No {
    public:
        No(const T& valor) : dado(valor), proximo(nullptr) {}
        T dado;
        No* proximo;
    };

    int qtdElementos;
    No* inicio;
    
public:

    class Iterator {
    No* atual;
        public:
            Iterator(No* v) : atual(v) {}
            T& operator*() { return atual->dado; }
            Iterator& operator++() { atual=atual->proximo; return *this; }
            bool operator!=(const Iterator& other) const { return atual != other.atual; }
    };
    
    Iterator begin() { return Iterator(inicio); }
    Iterator end()   { return Iterator(nullptr); }
    
    
    // ---------------------------
    // Métodos normais da lista
    // ---------------------------
    ListaEncadeada() : qtdElementos(0), inicio(nullptr) {}
    ~ListaEncadeada() {
        while (inicio != nullptr) {
            No* temp = inicio;
            inicio = inicio->proximo;
            delete temp;
        }
    }

    bool inserirInicio(const T& valor) {
        No* novo = new No(valor);
        if (!novo) return false;
        novo->proximo = inicio;
        inicio = novo;
        qtdElementos++;
        return true;
    }

    bool inserirFim(const T& valor) {
        No* novo = new No(valor);
        if (!novo) return false;

        if (!inicio) {
            inicio = novo;
        } else {
            No* temp = inicio;
            while (temp->proximo != nullptr) {
                temp = temp->proximo;
            }
            temp->proximo = novo;
        }
        qtdElementos++;
        return true;
    }

    bool inserir(const T& valor, int pos) {
        if (pos < 0 || pos > qtdElementos) return false;
        if (pos == 0) return inserirInicio(valor);

        No* novo = new No(valor);
        if (!novo) return false;

        No* temp = inicio;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->proximo;
        }
        novo->proximo = temp->proximo;
        temp->proximo = novo;
        qtdElementos++;
        return true;
    }

    bool remover(int pos) {
        if (pos < 0 || pos >= qtdElementos || !inicio) return false;

        No* temp = inicio;
        if (pos == 0) {
            inicio = inicio->proximo;
        } else {
            No* anterior = nullptr;
            for (int i = 0; i < pos; i++) {
                anterior = temp;
                temp = temp->proximo;
            }
            anterior->proximo = temp->proximo;
        }
        delete temp;
        qtdElementos--;
        return true;
    }

    T* getElemento(int pos) const {
        if (pos < 0 || pos >= qtdElementos) return nullptr;
        No* temp = inicio;
        for (int i = 0; i < pos; i++) temp = temp->proximo;
        return &(temp->dado);
    }

    int getQtdElementos() const { return qtdElementos; }

    // Sobrecarga do operador <<
    friend ostream& operator<<(ostream& os, const ListaEncadeada<T>& lista) {
        typename ListaEncadeada<T>::No* temp = lista.inicio;
        os << "[ ";
        while (temp != nullptr) {
            os << temp->dado << " ";
            temp = temp->proximo;
        }
        os << "]";
        return os;
    }
};

#endif
