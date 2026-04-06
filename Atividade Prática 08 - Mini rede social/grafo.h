#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include <list>
using namespace std;

class Grafo {
private:
    int num_vertices; 
    struct Vertice {
        int id;
        string nome; 
    };

    list<Vertice> usuarios;
    vector<vector<bool>> matriz_adj;

public:
    Grafo();
    Grafo(int num_vertices);
    ~Grafo();

    bool adicionaUsuario(int id, const string& nome);
    bool adicionaAmizade(int id1, int id2);
    bool removeAmizade(int id1, int id2);
    bool saoAmigos(int id1, int id2) const; //true se as duas pessoas sao amigas
    vector<string> listaAmigos(int id) const;
    void exibirRede() const;
};

#endif // GRAFO_H
