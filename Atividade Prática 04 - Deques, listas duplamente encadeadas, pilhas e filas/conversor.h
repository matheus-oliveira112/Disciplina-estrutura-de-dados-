#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include <vector>
using namespace std;

// Retorna a precedência de um operador
int precedencia(char op);

// Verifica se é um operador válido
bool ehOperador(char c);

// Quebra a expressão em tokens (números, operadores, parênteses)
vector<string> tokenize(const string& expr);

// Converte expressão infixa -> pós-fixa (a ser implementado pelo aluno)
string infixToPostfix(const string& expr);

#endif
