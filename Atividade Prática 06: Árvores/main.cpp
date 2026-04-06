#include "arvore.h"
#include <iostream>
using namespace std;

int main() {
    Arvore<string> empresa;
    
    //Define a raiz diretoria
    auto* diretoria = empresa.definirRaiz("Diretoria");

    //Filhos de diretoria
    auto* comercial  = diretoria->inserirFilho("Comercial");
    auto* financeiro = diretoria->inserirFilho("Financeiro");
    auto* ti         = diretoria->inserirFilho("TI");
    
    //Filhos de comercial
    comercial->inserirFilho("Vendas");
    comercial->inserirFilho("Marketing");

    //Filhos de financeiro
    financeiro->inserirFilho("Contabilidade");
    financeiro->inserirFilho("Planejamento");

    //Filhos de TI
    ti->inserirFilho("Infraestrutura");
    auto* desenvolvimento = ti->inserirFilho("Desenvolvimento");

    //Filhos de desenvolvimento
    desenvolvimento->inserirFilho("Analista");
    desenvolvimento->inserirFilho("Programador");

    cout << "Pré-ordem:\n";
    empresa.exibirPreOrdem();

    cout << "\nParênteses aninhados:\n";
    empresa.exibirParentesesAninhados();

    cout << "\nEstilo tree ASCII:\n";
    empresa.exibirPorNiveis();
}
