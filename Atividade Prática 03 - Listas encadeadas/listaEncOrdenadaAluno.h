#ifndef LISTA_ENC_ORDENADA_ALUNO_H
#define LISTA_ENC_ORDENADA_ALUNO_H

#include "listaEncAluno.h"

class ListaEncadeadaOrdenadaAluno : public ListaEncadeadaAluno {
public:

    ListaEncadeadaOrdenadaAluno();
    
    // TODO: implementar no .cpp
    // nota: é uma construtora alternativa, o compilador decide qual deve
    // ser chamada de acordo com o parametro sendo passado (ou nao).
    // isto é chamado de sobrecarga de operadores.
    ListaEncadeadaOrdenadaAluno(const ListaEncadeadaAluno& outra);

    
    // TODO: implementar no .cpp
    // insere de forma ordenada pela matrícula
    bool inserir(const Aluno& a);


    // TODO: implementar no .cpp
    ListaEncadeadaOrdenadaAluno mesclar(const ListaEncadeadaOrdenadaAluno& outra) const;
    
    private:
    // Estes metodos sao proibidos pois nao garantem a manutenção da ordenação
    using ListaEncadeadaAluno::inserir;       // versão por posição
    using ListaEncadeadaAluno::inserirInicio;
    using ListaEncadeadaAluno::inserirFim;
};

#endif
