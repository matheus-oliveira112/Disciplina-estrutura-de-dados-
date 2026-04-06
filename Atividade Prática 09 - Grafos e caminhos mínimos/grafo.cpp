#include "grafo.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Grafo::Grafo(int num_vertices) : matriz(num_vertices, vector<float>(num_vertices, -1.0f)) {}

Grafo::~Grafo() = default;

bool Grafo::insere_aresta(int v1, int v2, float peso) {
    if (v1 < 0 || v2 < 0 || v1 >= num_vertices() || v2 >= num_vertices()) return false;
    matriz[v1][v2] = peso;
    return true;
}

bool Grafo::retira_aresta(int v1, int v2) {
    if (!tem_aresta(v1, v2)) return false;
    matriz[v1][v2] = -1.0f;
    return true;
}

bool Grafo::tem_aresta(int v1, int v2) const {
    if (v1 < 0 || v2 < 0 || v1 >= num_vertices() || v2 >= num_vertices()) return false;
    return matriz[v1][v2] != -1.0f;
}

float Grafo::peso_aresta(int v1, int v2) const {
    if (v1 < 0 || v2 < 0 || v1 >= num_vertices() || v2 >= num_vertices()) return -1.0f;
    return matriz[v1][v2];
}

void Grafo::imprime() const {
    for (int i = 0; i < num_vertices(); ++i) {
        cout << "Vértice " << i << ":";
        for (int j = 0; j < num_vertices(); ++j) {
            if (matriz[i][j] != -1.0f) {
                cout << " (" << j << ", " << std::fixed << std::setprecision(2) << matriz[i][j] << ")";
            }
        }
        cout << '\n';
    }
}

Grafo Grafo::le_grafo_arquivo(const string& nome_arquivo) {
    ifstream f(nome_arquivo);
    if (!f) throw runtime_error("Erro ao abrir arquivo " + nome_arquivo);

    int num_vertices;
    if (!(f >> num_vertices)) throw runtime_error("Erro ao ler número de vértices");

    Grafo G(num_vertices);

    int origem, destino;
    float peso;
    while (f >> origem >> destino >> peso) {
        G.insere_aresta(origem, destino, peso);
    }
    return G;
}
