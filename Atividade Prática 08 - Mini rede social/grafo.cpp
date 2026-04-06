#include "grafo.h"
#include <iostream>
using namespace std;

Grafo::Grafo() : num_vertices(0) {
    //cria uma matriz vazia
    matriz_adj = vector<vector<bool>>();
}

Grafo::Grafo(int num_vertices) : num_vertices(num_vertices) {
    matriz_adj = vector<vector<bool>>(
        num_vertices,
        vector<bool>(num_vertices, false));
}

Grafo::~Grafo() {
    matriz_adj.clear();
}

bool Grafo::adicionaUsuario(int id, const string& nome) {
    for (const auto& v : usuarios) {    // verifica se o usuário já existe
        if (v.id == id)
            return false; 
    }

    Vertice novo;
    novo.id = id;
    novo.nome = nome;

    // Adiciona ao vetor de vértices
    usuarios.push_back(novo);

    return true;
}

bool Grafo::adicionaAmizade(int id1, int id2) {
    if (id1 < 1 || id1 > num_vertices || id2 < 1 || id2 > num_vertices)   //Checa se o id eh valido
        return false;
        
    matriz_adj[id1-1][id2-1] = true;
    matriz_adj[id2-1][id1-1] = true;
    return true;
}

bool Grafo::removeAmizade(int id1, int id2) {
    if (id1 < 1 || id1 > num_vertices || id2 < 1 || id2 > num_vertices)
        return false;
        
    matriz_adj[id1-1][id2-1] = false;
    matriz_adj[id2-1][id1-1] = false;
    return true;
}

bool Grafo::saoAmigos(int id1, int id2) const {
    if (id1 < 1 || id1 > num_vertices || id2 < 1 || id2 > num_vertices)
        return false;
        
    if(matriz_adj[id1-1][id2-1] == true) {
        return true;
    }
    return false;
}

vector<string> Grafo::listaAmigos(int id) const {
    vector<string> amigos;

    if (id < 1 || id > num_vertices)
        return amigos; // retorna lista vazia

    // Percorre todos os vértices 
    int idx = 0;
    for (const auto& v : usuarios) {
        if (matriz_adj[id-1][v.id-1]) {  // se há amizade
            amigos.push_back(v.nome);
        }
        idx++;
    }

    return amigos;
}

void Grafo::exibirRede() const {
    cout << "===== Rede Social =====" << endl;

    // percorre cada usuário da lista
    for (const auto& v : usuarios) {
        cout << v.id << " - " << v.nome << ": ";

        bool temAmigo = false;

        // percorre novamente todos os vértices para verificar amizades
        for (const auto& u : usuarios) {
            if (matriz_adj[v.id-1][u.id-1]) {  // se há amizade
                cout << u.nome << " ";
                temAmigo = true;
            }
        }

        if (!temAmigo)
            cout << "(sem amigos)";
        
        cout << endl;
    }

    cout << "=======================" << endl;
}
