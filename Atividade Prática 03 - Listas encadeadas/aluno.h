#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
public:
    // Construtor exige sempre dados válidos
    Aluno(int matricula, const string& nome);

    int getMatricula() const;
    string getNome() const;
    void setMatricula(int novaMatricula);
    void setNome(const string& novoNome);

private:
    int matricula;
    string nome;
};

#endif
