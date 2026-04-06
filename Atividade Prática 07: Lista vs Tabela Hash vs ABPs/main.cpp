#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>


using namespace std;

struct Produto {
    int id;
    string nome;
    double preco;
};

// ---------------------------------------------------------
// 🔹 Funções de medição (TODOS VAZIOS)
// ---------------------------------------------------------

//Funcão que mede o tempo da inserção na lista
long long medirInsercaoList(const vector<Produto>& produtos, list<Produto>& lst) {
    auto inicio = chrono::high_resolution_clock::now();

    for (const auto& p : produtos) {
    lst.push_back(p);           //Insere o produto na lista
}   

    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

//Funcão que mede o tempo da inserção na tabela hash
long long medirInsercaoTabela(const vector<Produto>& produtos, unordered_map<int, Produto> umap) {
    auto inicio = chrono::high_resolution_clock::now();

    for (const auto& p : produtos) {
        umap[p.id] = p;  //Insere o produto com a chave sendo o ID
    }

    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

//Funcão que mede o tempo da inserção na arvore binaria
long long medirInsercaoArvore(const vector<Produto>& produtos, map<int, Produto> omap) {
    auto inicio = chrono::high_resolution_clock::now();

    for (const auto& p : produtos) {
        omap.emplace(p.id, p);  //Usa o ID como criterio de comparação dentro da arvore para organizar e manter balanceada a árvore
    }

    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

bool buscarNaLista(const list<Produto>& lst, int idBusca) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it->id == idBusca) {
            return true; // achou, encerra a função
        }
    }
    return false; // percorreu tudo e não achou
}

long long medirBuscaList(const list<Produto>& lst, const vector<int>& buscas) {
    auto inicio = chrono::high_resolution_clock::now();
    for (int id : buscas) {     //Percorre os elementos presentes dentro do vector buscas
        buscarNaLista(lst, id);     //Chama a função que busca o id atual
    }
    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

long long medirBuscaTabela(const unordered_map<int, Produto>& umap, const vector<int>& buscas) {
    auto inicio = chrono::high_resolution_clock::now();
    for (int id : buscas) {
        if (umap.find(id) != umap.end()) {
            //Ao encontrar vai pro proximo
        }
    }
    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

long long medirBuscaArvore(const map<int, Produto>& omap, const vector<int>& buscas) {
    auto inicio = chrono::high_resolution_clock::now();
     for (int id : buscas) {
        if (omap.find(id) != omap.end()) {
            //Ao encontrar vai pro proximo
            //cout << "teste" << endl;

        }
    }
    auto fim = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
}

// ---------------------------------------------------------
// 🔹 Função principal
// ---------------------------------------------------------
int main() {
    vector<Produto> produtos;
    vector<int> buscas;

    int id_1;
    double preco_1;
    string linha;
    string id_2, nome_2, preco_2; 

    // Leitura do arquivo "produtos.txt" e e escrita no vector produtos
    ifstream entrada("produtos.txt", ios_base::in);
    if (!entrada.is_open()) {
        cout << "Impossivel abrir arquivo" << endl;
        return 1;
    }

    while (getline(entrada, linha)) {     // Loop para ler cada linha do arquivo
        stringstream ss(linha); // stringstream para processar a linha
        getline(ss, id_2, ' ');  
        getline(ss, nome_2, ' '); 
        getline(ss, preco_2, ' ');
        id_1 = stoi(id_2);    // Converte o id de string para int
        preco_1 = stod(preco_2);      //Converte o preco de string para double
        Produto p;
        p.id = id_1;
        p.nome = nome_2;   // aqui vai o nome lido
        p.preco = preco_1;   // preço lido
        produtos.push_back(p);  // adiciona ao vector produtos
    }
    entrada.close();

    // Leitura do arquivo "buscas.txt" e e escrita no vector buscas
    ifstream entrada2("buscas.txt", ios_base::in);
    if (!entrada2.is_open()) {
        cout << "Impossivel abrir arquivo" << endl;
        return 1;
    }

    while (getline(entrada2, id_2)) {     // Loop para ler cada linha do arquivo
        id_1 = stoi(id_2);    // Converte o id de string para int
        buscas.push_back(id_1);  // adiciona ao vector buscas
    }
    entrada2.close();
    

    list<Produto> lst;
    unordered_map<int, Produto> umap;
    map<int, Produto> omap;

    cout << "\n==== TESTE DE INSERÇÃO ====\n";
    //Tempo inserção na lista
    auto tempo = medirInsercaoList(produtos, lst);
    cout << "List: " << tempo << " µs" << endl;

    //Tempo inserção na tabela hash
    tempo = medirInsercaoTabela(produtos, umap);
    cout << "Tabela hash: " << tempo << " µs" << endl;

    //Tempo inserção na arvore binaria balanceada
    tempo = medirInsercaoArvore(produtos, omap);
    cout << "Arvore binaria: " << tempo << " µs" << endl;

    cout << "\n==== TESTE DE BUSCA ====\n";
    //Tempo busca na arvore
    auto tempoBusca = medirBuscaArvore(omap, buscas);
    cout << "List: " << tempoBusca << " µs" << endl;

    //Tempo busca na tabela
    tempoBusca = medirBuscaTabela(umap, buscas);
    cout << "List: " << tempoBusca << " µs" << endl;
    
    //Tempo busca na lista
    tempoBusca = medirBuscaList(lst, buscas);
    cout << "List: " << tempoBusca << " µs" << endl;

    return 0;
}
