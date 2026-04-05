#include "Deque.h"
#include "Aluno.h"
#include <iostream>
using namespace std;

int main() {
    Deque d1, d2;

    d1.insere_fim(Aluno(10, "Ana"));
    d1.insere_fim(Aluno(8, "Bruno"));

    d2.insere_fim(Aluno(9, "Carlos"));
    d2.insere_fim(Aluno(7, "Diana"));

    Deque d3 = d1 + d2;

    cout << "d1: ";
    d1.imprimir();

    cout << "d2: ";
    d2.imprimir();

    cout << "d3 (concatenação): ";
    d3.imprimir();

    d1 += d2;
    cout << "d1 depois de += d2: ";
    d1.imprimir();

    return 0;
}
