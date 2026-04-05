#include <iostream>
#include "conversor.h"
using namespace std;

/**
 * exemplos:
 * 
 * Entrada:   (1 + 2) * (3 + 4)
 * Saída:     1 2 + 3 4 + *
 * 
 * Entrada:   3 + 4 * 2 / ( 1 - 5 )
 * Saída:     3 4 2 * 1 5 - / +
 * */

int main() {
    string expr;
    cout << "Digite uma expressão infixada: ";
    getline(cin, expr);

    vector<string> tokens = tokenize(expr);
    cout << "Tokens: ";
    for (auto& t : tokens) { 
        cout << "[" << t << "] ";
    }
    cout << endl;

    string posfixa = infixToPostfix(expr);
    cout << "Expressão pós-fixa: " << posfixa << endl;

    return 0;
}
