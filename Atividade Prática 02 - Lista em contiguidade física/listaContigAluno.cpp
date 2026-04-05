#include "listaContigAluno.h"
#include <iostream>

// --- Implementação da classe Aluno ---

Aluno::Aluno(int matricula, const std::string& nome) {
    this->matricula = matricula;
    this->nome = nome;
}
int Aluno::getMatricula() const { return matricula; }
std::string Aluno::getNome() const { return nome; }
void Aluno::setMatricula(int novaMatricula) { this->matricula = novaMatricula; }
void Aluno::setNome(const std::string& novoNome) { this->nome = novoNome; }

// --- Implementação da classe ListaContigAluno ---

ListaContigAluno::ListaContigAluno(int capacidade) {
    this->capacidade = capacidade;
    this->qtdElementos = 0;
    this->vetorAlunos = new Aluno[capacidade];
}
ListaContigAluno::~ListaContigAluno() {
    delete[] vetorAlunos;
}

bool ListaContigAluno::inserirFim(const Aluno& a) {
    if (qtdElementos < capacidade) {
        vetorAlunos[qtdElementos] = a;
        qtdElementos++;
        return true;
    }
    return false;
}
bool ListaContigAluno::remover(int pos) {
    if (pos < 0 || pos >= qtdElementos) return false;
    for (int i = pos; i < qtdElementos - 1; i++) {
        vetorAlunos[i] = vetorAlunos[i+1];
    }
    qtdElementos--;
    return true;
}
void ListaContigAluno::exibir() const {
    std::cout << "--- LISTA DE ALUNOS (" << qtdElementos << " de " << capacidade << ") ---" << std::endl;
    for (int i = 0; i < qtdElementos; i++) {
        std::cout << "Matrícula: " << vetorAlunos[i].getMatricula()
                  << ", Nome: " << vetorAlunos[i].getNome() << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}
int ListaContigAluno::buscarMatricula(int matricula) const {
    for (int i = 0; i < qtdElementos; i++) {
        if (vetorAlunos[i].getMatricula() == matricula) {
            return i;
        }
    }
    return -1;
}

Aluno* ListaContigAluno::getAluno(int pos) {
    if (pos >= 0 && pos < qtdElementos) {
        return &vetorAlunos[pos];
    }
    return nullptr;
}

int ListaContigAluno::getQtdElementos() const {
    return qtdElementos;
}


// Implementação da função buscarNome
int ListaContigAluno::buscarNome(const std::string nome) const {
    for (int i = 0; i < qtdElementos; i++) {
        if (vetorAlunos[i].getNome() == nome) {
            return i;
        }
    }
    return -1;
}

// Implementação da função inserir por posição
bool ListaContigAluno::inserir(const Aluno& a, int pos) {
    if (qtdElementos < capacidade) {
        for(int i = qtdElementos; i > pos; i--) {
            vetorAlunos[i] = vetorAlunos[i-1];
            if(i==(pos+1)){
                vetorAlunos[pos] = a;
            }
            }
        
        qtdElementos++;
        return true;
    }
    return false;
}

// Implementação da função removerPorMatricula
bool ListaContigAluno::removerPorMatricula(int matricula) {
for (int i = 0; i < qtdElementos; i++) {
        if (vetorAlunos[i].getMatricula() == matricula) {
            int pos = i;
            for (int j = pos; j < qtdElementos - 1; j++) {
            vetorAlunos[j] = vetorAlunos[j+1];
        }
            qtdElementos--;
            return true;
        }
    }
    return false;
}


