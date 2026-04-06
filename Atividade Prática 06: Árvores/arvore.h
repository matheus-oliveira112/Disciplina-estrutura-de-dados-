#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

template <typename T>
class Nodo {
public:
    T dado;
    Nodo<T>* pai;
    vector<Nodo<T>*> filhos;

    Nodo(const T& valor) : dado(valor), pai(nullptr) {}

    Nodo<T>* inserirFilho(const T& valor) {
        Nodo<T>* novo = new Nodo<T>(valor);
        novo->pai = this;
        filhos.push_back(novo);
        return novo;
    }

    bool ehUltimoFilho() const {
        if (!pai) return true;
        return pai->filhos.back() == this;
    }
};

template <typename T>
class Arvore {
private:
    Nodo<T>* raiz;

public:
    Arvore() : raiz(nullptr) {}
    Arvore(const T& valorRaiz) { raiz = new Nodo<T>(valorRaiz); }

    Nodo<T>* obterRaiz() const { return raiz; }
    
    Nodo<T>* definirRaiz(const T& valor) {
        raiz = new Nodo<T>(valor);
        return raiz;
    }

    bool vazia() const { return raiz == nullptr; }


    // --- Exibir com parênteses aninhados 
    void exibirParentesesAninhados() const {
        if (vazia()) return;
        exibirParentesesAninhadosRec(raiz);
        cout << endl;
    }
    
    
    // --- Exibir estilo "tree" ASCII ---
    void exibirPorNiveis() const {
        if (vazia()) return;
        cout << raiz->dado <<endl; 
        exibirPorNiveisRec(raiz, "");
        cout << endl;
    }
    
    // --- Exibir em pré-ordem (versão recursiva) ---
    void exibirPreOrdem() const {
        if (vazia()) return;
        exibirPreOrdemRec(raiz);
        cout << endl;
    }
    
    private:
    void exibirPreOrdemRec(Nodo<T>* nodo) const {
        if (!nodo) return;
    
        cout << nodo->dado << " ";
    
        // percorre todos os filhos do nó atual
        for (auto* filho : nodo->filhos) {
            exibirPreOrdemRec(filho);
        }
    }
    
    void exibirParentesesAninhadosRec(Nodo<T>* nodo) const {
        if (!nodo) return;

        cout << nodo->dado;                       // imprime o nó
        if (nodo->filhos.empty()) return;         // se o nodo nao tem filho retorna
        cout << "(";                               // tem filhos → abre

        for (int i = 0; i < nodo->filhos.size(); ++i) {
            exibirParentesesAninhadosRec(nodo->filhos[i]);
            if (i + 1 < nodo->filhos.size())      // vírgula entre filhos
                cout << ",";
    }

        cout << ")";                               // fecha após todos os filhos
    }
    
    void exibirPorNiveisRec(Nodo<T>* nodo, string prefixo) const {
        if (!nodo) return;
        cout << "    ";
        // percorre todos os filhos do nó atual
        for (int i = 0; i < nodo->filhos.size(); ++i) {
            bool ultimo = (i + 1 == nodo->filhos.size());

            cout << prefixo << (ultimo ? "\\-- " : "+-- ") << nodo->filhos[i]->dado << endl;

            // chamada recursiva com prefixo atualizado
            exibirPorNiveisRec(nodo->filhos[i], prefixo + (ultimo ? "    " : "|   "));
    }
        
    }
};


#endif // ARVORE_H
