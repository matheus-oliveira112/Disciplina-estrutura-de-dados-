#ifndef LISTACONTIGALUNOS_H
#define LISTACONTIGALUNOS_H

#include <string>

class Aluno {
public:
    Aluno() = default; 
    Aluno(int matricula, const std::string& nome);
    int getMatricula() const;
    std::string getNome() const;
    void setMatricula(int novaMatricula);
    void setNome(const std::string& novoNome);
private:
    int matricula;
    std::string nome;
};

// ---

class ListaContigAluno {
public:
    ListaContigAluno(int capacidade); // Construtor 
    ~ListaContigAluno(); // Destrutor para liberar a memória

    // Métodos da lista
    bool inserirFim(const Aluno& a);
    bool remover(int pos);
    void exibir() const;
    int buscarMatricula(int matricula) const;
    Aluno* getAluno(int pos);
    int getQtdElementos() const;
    
    // Metodos não implementados
    
    /**
     * Retorna o índice do aluno na lista de acordo com o seu nome
     * Caso nao seja encontrado, retorna -1
     */
    int buscarNome(const std::string nome) const;
    
    /**
     * Insere o aluno na posicao informada, se ela for valida.
     * Retorna true se deu certo e false em erro (lista cheia ou posicao invalida)
     */
    bool inserir(const Aluno& a, int pos);
    
    
    /**
     * Remove o aluno com a matricula informada, retorna true se deu certo
     * e false se o aluno nao foi encontrado
     */
    bool removerPorMatricula(int matricula);
    
    
private:
    int qtdElementos;
    int capacidade;
    Aluno* vetorAlunos; 
};


#endif // LISTA_CONTIG_ALUNOS_H