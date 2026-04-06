#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <string>

using namespace std;

class Grafo {
public:
    Grafo(int num_vertices);

    // metodo estatico, para usa-lo: Grafo G = Grafo::le_grafo_arquivo("caminho/para/arquivo.txt");
    static Grafo le_grafo_arquivo(const string& nome_arquivo);
    ~Grafo();

    int num_vertices() const { return (int)matriz.size(); }
    bool insere_aresta(int v1, int v2, float peso);
    bool retira_aresta(int v1, int v2);
    bool tem_aresta(int v1, int v2) const;
    float peso_aresta(int v1, int v2) const;
    void imprime() const;

private:
    vector<vector<float>> matriz; // -1.0 indica ausência de aresta
};

#endif // GRAFO_HPP
