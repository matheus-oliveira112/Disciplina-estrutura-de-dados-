//Nome: Matheus Santos de Oliveira

#include <iostream> 
#include <stdio.h>

using namespace std;

void inverte(int *a, int n);

int main() {
    int vetor[] = {1, 2, 3, 4 ,5, 6, 7, 8};
    int n;
    int i;

    n = sizeof(vetor)/sizeof(vetor[0]);     //Numero de elementos do vetor


    cout<<"Os valores do vetor sao:"<<endl;

    for(i = 0; i<n; i++) {
        cout<<vetor[i]<<' ';
    }   

    inverte(vetor, n);
    
    return 0;
}

void inverte(int *a, int n) {

int aux;
int i;
int j = n-1;
int metade = n/2;       //Divisao por inteiro  Ex:5/2=2
                        //Faz com que o loop a seguir sempre va ate a metade

for(i=0; i<metade; i++) {
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
    j--;
}

cout<<"\nOs valores do vetor invertido sao:"<<endl;

for(i = 0; i<n; i++) {
    cout<<a[i]<<' ';
}

}
