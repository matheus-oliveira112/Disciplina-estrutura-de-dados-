#include "dijkstra.hpp"
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct PQItem {
    int v;
    float d;
    bool operator<(const PQItem& o) const { return d > o.d; } // menor d tem maior prioridade
};

Dijkstra::Dijkstra(const Grafo& G_, int origem) : G(G_), src(origem), dist(G_.num_vertices(), INF), pred(G_.num_vertices(), -1) {
    if (origem < 0 || origem >= G.num_vertices()) throw runtime_error("Origem fora do intervalo");

    dist[origem] = 0.0f;
    priority_queue<PQItem> pq;
    pq.push({origem, 0.0f});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int u = top.v;
        float d_u = top.d;
        if (d_u > dist[u]) continue; // entrada antiga

        for (int v = 0; v < G.num_vertices(); ++v) {
            float peso = G.peso_aresta(u, v);
            if (peso != -1.0f) {
                float nd = dist[u] + peso;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pred[v] = u;
                    pq.push({v, nd});
                }
            }
        }
    }
}

vector<int> Dijkstra::reconstroi_caminho(int destino) const {
    vector<int> tmp;
    if (destino < 0 || destino >= num_vertices()) return tmp;
    if (dist[destino] == INF) return tmp; // sem caminho

    int atual = destino;
    while (atual != -1 && atual != src) {
        tmp.push_back(atual);
        atual = pred[atual];
    }
    if (atual == -1) return vector<int>();
    tmp.push_back(src);
    std::reverse(tmp.begin(), tmp.end());
    return tmp;
}

void Dijkstra::imprime_caminho(int destino) const {
    if (destino == src) {
        cout << "Origem e destino são o mesmo vértice (" << src << ").\n";
        return;
    }
    auto caminho = reconstroi_caminho(destino);
    if (caminho.empty()) {
        cout << "Sem caminho de " << src << " a " << destino << ".\n";
        return;
    }
    cout << "Caminho de " << src << " a " << destino << " (custo " << std::fixed << std::setprecision(2) << dist[destino] << "): ";
    for (size_t i = 0; i < caminho.size(); ++i) {
        cout << caminho[i];
        if (i + 1 < caminho.size()) cout << " -> ";
    }
    cout << '\n';
}
