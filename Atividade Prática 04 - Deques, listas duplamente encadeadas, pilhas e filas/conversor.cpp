#include "conversor.h"
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <stack> 

using namespace std;

// -------------------------------
// Função de precedência
// -------------------------------
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// -------------------------------
// Verifica se é operador
// -------------------------------
bool ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// -------------------------------
// Tokenização
// -------------------------------
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    string num;

    for (char c : expr) {
        if (isspace(c)) continue;

        if (isdigit(c)) {
            num += c;
        } else {
            if (!num.empty()) {
                tokens.push_back(num);
                num.clear();
            }
            tokens.push_back(string(1, c));
        }
    }
    if (!num.empty()) tokens.push_back(num);

    return tokens;
}

// -------------------------------
// Conversão infixa -> pós-fixa
// (ESQUELETO para os alunos preencherem)
// -------------------------------
string infixToPostfix(const string& expr) {
    vector<string> tokens = tokenize(expr);
    stack<char> s;
    string saida;
    
    for (int i = 0; i < tokens.size(); i++) {
        if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "(" && tokens[i] != ")") {
            saida += tokens[i];
            saida += ' ';
        }
        else {
            if (tokens[i] == "(") {       //empilha
            s.push('(');
        }
            else if (tokens[i] == ")") {      //Começa a desempilhar quando o caractere é ")"
                while (!s.empty() && s.top() != '(') {      //Para de desempilhar quando acha "("
                    saida += s.top();
                    saida += ' ';
                    s.pop();
    }
                if (!s.empty() && s.top() == '(') 
                    s.pop();                // descarta '('
}
            else {      //Caracteres + - * /
                string& tok = tokens[i];
                char operando = tok[0];
                
                while (!s.empty() && s.top() != '(' && precedencia(s.top()) >= precedencia(operando)) {     //Desempilha o operador se
                    saida += s.top();                                                                   //a precedencia do operador do infixToPostfix
                    saida += ' ';                                                                   //for >= ao operador atual
                    s.pop();
                }

                s.push(operando);     //Empilha o operador
            }    
        }
    
}
    while (!s.empty()) {    //Esvazia a lista
    saida += s.top();
    saida += ' ';
    s.pop();
}

    return saida; 
}
