#include "listaEncOrdenadaAluno.h"

ListaEncadeadaOrdenadaAluno::ListaEncadeadaOrdenadaAluno() 
    : ListaEncadeadaAluno() {}

// ====== construtora que gera uma lista ordenada a partir de uma 'comum'
ListaEncadeadaOrdenadaAluno::ListaEncadeadaOrdenadaAluno(const ListaEncadeadaAluno& outra) 
    : ListaEncadeadaAluno() 
{
    
}

// ===== Inserção ordenada =====
bool ListaEncadeadaOrdenadaAluno::inserir(const Aluno& a) {
    No* novo = new No(a);
    No* atual = inicio;
    //Insere na primeira posição, isto se a lista for vazia ou a matricula do novo aluno 
    //for menor que o primeiro elemento anterior
    if ((inicio == nullptr) || (novo->aluno.getMatricula()<atual->aluno.getMatricula())) {
        novo->proximo = inicio;
        inicio = novo;
        qtdElementos++;
        return true;
    }
    //Ponteiro "atual" é responsavel por avançar pelos nós da lista
    atual = inicio->proximo;
    //Ponteiro "temp" fica apontado para o nó anterior ao atual
    No* temp = inicio;
    //Conforme as comparações sao feitas ambos os ponteiros vao avançando para o proximo elemento
    while((atual!=nullptr) && (novo->aluno.getMatricula()>atual->aluno.getMatricula())) {
        temp = atual;
        atual = atual->proximo;
    }
    //Insere o novo aluno em uma nova posição, sendo ela no meio ou fim
        temp->proximo = novo;
        novo->proximo = atual;
        qtdElementos++;
        return true;
}

// ===== Mesclar duas listas ordenadas =====
ListaEncadeadaOrdenadaAluno 
ListaEncadeadaOrdenadaAluno::mesclar(const ListaEncadeadaOrdenadaAluno& outra) const {
    ListaEncadeadaOrdenadaAluno resultado;

    No* atual1 = inicio;
    No* atual2 = outra.inicio;
    No* ultimo = nullptr;   // último nó para o qual esta sendo apontado na lista resultado

    // enquanto as duas listas têm elementos
    while (atual1 != nullptr && atual2 != nullptr) {
        //entra se a matricula da lista 1 é menor que o da lista 2 
        if (atual1->aluno.getMatricula() <= atual2->aluno.getMatricula()) {
            No* n = new No(atual1->aluno);
            
            //Caso a lista resultado esteja vazia
            if (resultado.inicio == nullptr) {
                resultado.inicio = n;               //Apos as comparações o primeiro elemento é adicionada a lista mesclada
                ultimo = n;                         //Ponteiro ultimo aponta para esse primeiro elemento da lista
            //Caso a lista resultado nao esteja vazia
            } else {
                ultimo->proximo = n;                //Lista mesclada é atualizada
                ultimo = ultimo->proximo;           //Ponteiro avança
            }
            ++resultado.qtdElementos;
            atual1 = atual1->proximo;           //Ponteiro da lista 1 avança para o proximo elemento
        
        //entra se a matricula da lista 2 é menor que o da lista 1
        } else {
            No* n = new No(atual2->aluno);

            if (resultado.inicio == nullptr) {
                resultado.inicio = n;
                ultimo = n;
            } else {
                ultimo->proximo = n;
                ultimo = ultimo->proximo;
            }
            ++resultado.qtdElementos;
            atual2 = atual2->proximo;
        }
    }

    // insere o restante da lista 1 (se sobrar)
    while (atual1 != nullptr) {
        No* n = new No(atual1->aluno);

        if (resultado.inicio == nullptr) {
            resultado.inicio = n;
            ultimo = n;
        } else {
            ultimo->proximo = n;
            ultimo = ultimo->proximo;
        }
        ++resultado.qtdElementos;
        atual1 = atual1->proximo;
    }

    // insere o restante da lista 2 (se sobrar)
    while (atual2 != nullptr) {
        No* n = new No(atual2->aluno);

        if (resultado.inicio == nullptr) {
            resultado.inicio = n;
            ultimo = n;
        } else {
            ultimo->proximo = n;
            ultimo = ultimo->proximo;
        }
        ++resultado.qtdElementos;
        atual2 = atual2->proximo;
    }

    return resultado;
}
