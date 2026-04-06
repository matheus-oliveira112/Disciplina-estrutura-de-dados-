#include "grafo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void mostrarMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Mostrar rede completa\n";
    cout << "2. Mostrar amizades de uma pessoa\n";
    cout << "3. Adicionar amizade\n";
    cout << "4. Remover amizade\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Grafo rede;
    string linha;
    string id1, id2, nome;
    int id, id_adiciona;
    int i = 0;
    int limite = 0;
    vector<string> amigos;
    
 
    ifstream entrada("rede.txt");
    if (!entrada.is_open()) {
        cout << "Impossivel abrir arquivo" << endl;
        return 1;
    }
    
    while (getline(entrada, linha)) {     // Loop para ler cada linha do arquivo
        //Parte que le o numero de vertices
        if(i==0) {
            limite = stoi(linha);
            rede = Grafo(limite);
            i++;
        }
        
        //Parte que adicona os usuarios
        else if((i>=1)&&(i<=limite)) {
        stringstream ss(linha); // stringstream para processar a linha
        getline(ss, id1, ' ');  
        getline(ss, nome, ' '); 
        id = stoi(id1);    // Converte o id de string para int
        rede.adicionaUsuario(id, nome);
        i++;
        }
        
        //Parte que adiciona as amizades
        else if(i>limite) {
        stringstream ss(linha); 
        getline(ss, id1, ' ');  
        getline(ss, id2, ' '); 
        id = stoi(id1);
        id_adiciona = stoi(id2);
        rede.adicionaAmizade(id, id_adiciona);
        i++;
        }
    }
    entrada.close();
    
     
    // menu interativo: 
    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "\nRede social completa:\n";
                rede.exibirRede();
                break;

            case 2: {
                cout << "\nDigite o ID para ver a lista de amigos: ";
                cin >> id;
                amigos = rede.listaAmigos(id);
                if (amigos.empty()) {
                    cout << "Este usuário não possui amigos cadastrados.\n";
                } 
                else {
                    cout << "Amigos do usuário " << id << ": ";
                        for (const auto& nome : amigos) {
                            cout << nome << " ";
                        }
                cout << endl;
                }
                break;
            }

            case 3: {
                cout << "\nDigite os IDs para adicionar uma amizade: ";
                cin >> id >> id_adiciona;

                if (rede.adicionaAmizade(id, id_adiciona))
                    cout << "Amizade adicionada com sucesso!\n";
                else
                    cout << "Falha ao adicionar amizade (IDs inválidos).\n";

                break;
            }

            case 4: {
                cout << "\nDigite os IDs para remover a amizade: ";
                cin >> id >> id_adiciona;

                if (rede.removeAmizade(id, id_adiciona))
                    cout << "Amizade removida com sucesso!\n";
                else
                    cout << "Falha ao remover amizade (IDs inválidos).\n";

                break;
                break;
            }

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
