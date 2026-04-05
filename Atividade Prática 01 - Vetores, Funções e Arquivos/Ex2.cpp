#include <string>
#include <tuple>  // para std::tuple e std::make_tuple
#include <iostream> 

using namespace std;
class Aluno {
    public:
    double p1;
    double p2;
    double tf;
    double labs;
};

// cabeçalho da função que calcula a nota final
//double calculaNota(double p1, double p2, double tf, double labs);

// cabeçalho da função que determina o conceito a partir da nota final
//char calculaConceito(double nf);

// [opcional] cabeçalho da função que calcula nota final e conceito ao mesmo tempo
tuple<double, char> notaEConceito(double p1, double p2, double tf, double labs);

int main() {

    Aluno aluno1;

    double nota;
    char conceito;

    //Le a nota da P1
    do{
    cout<<"Nota P1: ";
    cin>>aluno1.p1;
    if ((aluno1.p1>10)||(aluno1.p1<0)) {
        cout<<"ERRO, digite novamente"<<endl;
    }
    } while((aluno1.p1>10)||(aluno1.p1<0));

    //Le a nota da P2
    do{
    cout<<"Nota P2: ";
    cin>>aluno1.p2;
    if ((aluno1.p2>10)||(aluno1.p2<0)) {
        cout<<"ERRO, digite novamente"<<endl;
    }
    } while((aluno1.p2>10)||(aluno1.p2<0));

    //Le a nota do teste final
    do{
    cout<<"Nota Teste final: ";
    cin>>aluno1.tf;
    if ((aluno1.tf>10)||(aluno1.tf<0)) {
        cout<<"ERRO, digite novamente"<<endl;
    }
    } while((aluno1.tf>10)||(aluno1.tf<0));

    //Le a nota dos laboratorios
    do{
    cout<<"Nota laboratorios: ";
    cin>>aluno1.labs;
    if ((aluno1.labs>10)||(aluno1.labs<0)) {
        cout<<"ERRO, digite novamente"<<endl;
    }
    } while((aluno1.labs>10)||(aluno1.labs<0));

    tie(nota, conceito) = notaEConceito(aluno1.p1, aluno1.p2, aluno1.tf, aluno1.labs);

    cout<<"Nota final = "<< nota <<endl;
    cout<<"Conceito = "<< conceito <<endl;


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

