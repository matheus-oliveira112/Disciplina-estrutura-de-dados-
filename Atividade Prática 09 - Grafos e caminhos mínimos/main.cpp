#include <iostream>
#include <iomanip>
#include "grafo.hpp"
#include "dijkstra.hpp"

//ATENCAO: o projeto deve ser compilado em C++17 ou superior

using namespace std;

int main() {
    
    int v;
    
    Grafo G(5);

    // Insere arestas: origem, destino, peso
    G.insere_aresta(0, 0, 1.0f);    // A -> A
    G.insere_aresta(0, 1, 2.0f);    // A -> B
    G.insere_aresta(0, 2, 7.0f);    // A -> C
    G.insere_aresta(1, 2, 3.0f);    // B -> C
    G.insere_aresta(1, 4, 8.0f);    // B -> E
    G.insere_aresta(2, 0, 3.0f);    // C -> A
    G.insere_aresta(2, 3, 1.0f);    // C -> D
    G.insere_aresta(2, 4, 4.0f);    // C -> E
    G.insere_aresta(3, 4, 2.0f);    // D -> E
    
    cout << "==== PARTE 1 ====\n";
    cout << "Grafo criado:\n";
    G.imprime();
    Dijkstra dj(G, 0);
    cout << "Caminhos minimos a partir de " << "A" << ":\n";
    for (v = 0; v < G.num_vertices(); ++v) {
        dj.imprime_caminho(v);  // já mostra caminho e custo
    }
    cout << "\n\n\n";
    
    cout << "==== PARTE 2 ====\n";
    Grafo G2 = Grafo::le_grafo_arquivo("entrada.txt");
    G2.imprime();
    Dijkstra dj2(G2, 0);
    cout << "Caminhos minimos a partir de " << "A" << ":\n";
    for (v = 0; v < G2.num_vertices(); ++v) {
        dj2.imprime_caminho(v);  
    }
    cout << "\n\n\n";
    
    return 0;
}
