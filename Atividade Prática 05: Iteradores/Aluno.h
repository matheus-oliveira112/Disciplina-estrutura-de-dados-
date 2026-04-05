#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>
using namespace std;

class Aluno {
public:
    Aluno(int matricula = 0, const string& nome = "");

    int getMatricula() const;
    string getNome() const;

    void setMatricula(int novaMatricula);
    void setNome(const string& novoNome);

    // Sobrecarga do operador de inserção <<
    friend ostream& operator<<(ostream& os, const Aluno& aluno);

private:
    int matricula;
    string nome;
};

#endif
