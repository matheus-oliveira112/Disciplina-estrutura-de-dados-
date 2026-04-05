#include "Aluno.h"

// Construtor
Aluno::Aluno(int matricula, const string& nome)
    : matricula(matricula), nome(nome) {}

// Getters
int Aluno::getMatricula() const {
    return matricula;
}

string Aluno::getNome() const {
    return nome;
}

// Setters
void Aluno::setMatricula(int novaMatricula) {
    matricula = novaMatricula;
}

void Aluno::setNome(const string& novoNome) {
    nome = novoNome;
}

// Sobrecarga do operador <<
ostream& operator<<(ostream& os, const Aluno& aluno) {
    os << "Aluno(Matricula: " << aluno.matricula
       << ", Nome: " << aluno.nome << ")";
    return os;
}
