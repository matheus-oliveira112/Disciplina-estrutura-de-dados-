#include "Aluno.h"

Aluno::Aluno(int matricula, const string& nome) : matricula(matricula), nome(nome) {}

int Aluno::getMatricula() const {
    return matricula;
}

string Aluno::getNome() const {
    return nome;
}

void Aluno::setMatricula(int novaMatricula) {
    matricula = novaMatricula;
}

void Aluno::setNome(const string& novoNome) {
    nome = novoNome;
}
