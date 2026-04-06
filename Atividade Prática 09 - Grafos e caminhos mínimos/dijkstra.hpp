#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <limits>
#include "grafo.hpp"

using namespace std;

class Dijkstra {
public:
    Dijkstra(const Grafo& G, int origem);
    const vector<float>& distancias() const { return dist; }
    const vector<int>& antecessores() const { return pred; }
    int origem() const { return src; }
    int num_vertices() const { return (int)dist.size(); }

    vector<int> reconstroi_caminho(int destino) const; 
    void imprime_caminho(int destino) const;

private:
    const Grafo& G;
    int src;
    vector<float> dist;
    vector<int> pred;
    static constexpr float INF = std::numeric_limits<float>::infinity();
};

#endif // DIJKSTRA_HPP
