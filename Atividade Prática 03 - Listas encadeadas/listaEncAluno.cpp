#include "listaEncAluno.h"

// Construtor
ListaEncadeadaAluno::ListaEncadeadaAluno() : inicio(nullptr), qtdElementos(0) {}

// Destrutor
ListaEncadeadaAluno::~ListaEncadeadaAluno() {
    No* atual = inicio;
    while (atual != nullptr) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
}

bool ListaEncadeadaAluno::inserirInicio(const Aluno& a) {
    No* novo = new No(a);
    novo->proximo = inicio;
    inicio = novo;
    qtdElementos++;
    return true;
}

bool ListaEncadeadaAluno::inserirFim(const Aluno& a) {
    No* novo = new No(a);
    if (inicio == nullptr) {
        inicio = novo;
    } else {
        No* atual = inicio;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    qtdElementos++;
    return true;
}

bool ListaEncadeadaAluno::inserir(const Aluno& a, int pos) {
    if (pos < 0 || pos > qtdElementos) return false;
    if (pos == 0) return inserirInicio(a);

    No* novo = new No(a);
    No* atual = inicio;
    for (int i = 0; i < pos - 1; i++) {
        atual = atual->proximo;
    }
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    qtdElementos++;
    return true;
}

bool ListaEncadeadaAluno::remover(int pos) {
    if (pos < 0 || pos >= qtdElementos) return false;

    No* atual = inicio;
    No* temp = nullptr;

    for (int i = 0; i < pos; i++) {
        temp = atual;
        atual = atual->proximo;
    }

    if (temp == nullptr) {
        inicio = atual->proximo;
    } else {
        temp->proximo = atual->proximo;
    }

    delete atual;
    qtdElementos--;
    return true;
}

int ListaEncadeadaAluno::buscarMatricula(int matricula) const {
    No* atual = inicio;
    int pos = 0;
    while (atual != nullptr) {
        if (atual->aluno.getMatricula() == matricula) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1; // não encontrado
}

Aluno* ListaEncadeadaAluno::getAluno(int pos) const {
    if (pos < 0 || pos >= qtdElementos) return nullptr;
    No* atual = inicio;
    for (int i = 0; i < pos; i++) {
        atual = atual->proximo;
    }
    return &(atual->aluno);
}

int ListaEncadeadaAluno::getQtdElementos() const {
    return qtdElementos;
}

void ListaEncadeadaAluno::exibir() const {
    No* atual = inicio;
    cout << "[ ";
    while (atual != nullptr) {
        cout << "(" << atual->aluno.getMatricula()
             << ", " << atual->aluno.getNome() << ") ";
        atual = atual->proximo;
    }
    cout << "]" << endl;
}

// ===== Exercício 1: operador== =====
bool ListaEncadeadaAluno::operator==(const ListaEncadeadaAluno& outra) const {
    No* atual1 = inicio;
    No* atual2 = outra.inicio;
    if(getQtdElementos()!=outra.getQtdElementos()) {    //Se o tamanho das listas é diferente ja se sabe que nao sao iguais
        return false;
    }
    while((atual1!= nullptr)&&(atual2!= nullptr)) {
        //Vai comparando nó por nó pra ver se matricula e nome são iguais nas duas listas
        if(((atual1->aluno.getMatricula())!=(atual2->aluno.getMatricula()))&&((atual1->aluno.getNome())!=(atual2->aluno.getNome()))) {
            return false;
        }
        atual1 = atual1->proximo;
        atual2 = atual2->proximo;
    }
    return true;
}

// ===== Exercício extra: inverter =====
void ListaEncadeadaAluno::inverter() {
    
}
