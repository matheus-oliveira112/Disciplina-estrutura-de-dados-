#include <string>
#include <tuple>  // para std::tuple e std::make_tuple
#include <iostream> 
#include <fstream>
#include <sstream>

using namespace std;

// cabeçalho da função que calcula a nota final
//double calculaNota(double p1, double p2, double tf, double labs);

// cabeçalho da função que determina o conceito a partir da nota final
//char calculaConceito(double nf);

// [opcional] cabeçalho da função que calcula nota final e conceito ao mesmo tempo
tuple<double, char> notaEConceito(double p1, double p2, double tf, double labs);

int main() {

    double nota_final;
    char conceito;
    string linha, nome, p1, p2, tf, labs; 
    double nota_p1, nota_p2, nota_tf, nota_labs;


    ifstream entrada("notas.txt"); 
    ofstream saida("resultado.txt");


    if ((!entrada.is_open()) || (!saida.is_open())) {
        cout << "Nao foi possivel abrir o(s) arquivo(s)!" << endl;
        return 1;
    }

    saida << "Nome, Nota final, Conceito" << endl;

    getline(entrada, linha);

    while (getline(entrada, linha)) {     // Loop para ler cada linha do arquivo
        stringstream ss(linha); // stringstream para processar a linha
        getline(ss, nome, ',');  
        getline(ss, p1, ','); 
        getline(ss, p2, ',');
        getline(ss, tf, ',');
        getline(ss, labs, ',');
        nota_p1 = stod(p1);    // Converte a idade de string para double
        nota_p2 = stod(p2);
        nota_tf = stod(tf);
        nota_labs = stod(labs);

        tie(nota_final, conceito) = notaEConceito(nota_p1, nota_p2, nota_tf, nota_labs);    //Funcao que retorna a nota final e o conceito
        saida << nome <<", " << nota_final << ", "<<conceito <<endl;        //Escreve no arquivo de saida o nome, nota final e conceito
    }


    return 0;
}

tuple<double, char> notaEConceito(double p1, double p2, double tf, double labs) {
    double nf;
    char conceito; 
 
    nf=(p1*0.3)+(p2*0.3)+(tf*0.2)+(labs*0.2);

    if(nf>=9) {
        conceito = 'A';
    }
    else if((nf<9)&&(nf>=7.5)) {
        conceito = 'B';
    }
    else if((nf<7.5)&&(nf>=6)) {
        conceito = 'C';
    }
    else {
        conceito = 'D';
    }

    return  make_tuple(nf, conceito);
}

