#include <iostream>

using namespace std;

// Definição da estrutura de nó para a árvore binária de busca
struct No
{
    int info; // Valor do nó
    No *esq;  // Ponteiro para o filho esquerdo
    No *dir;  // Ponteiro para o filho direito
};

// Classe que representa uma árvore binária de busca
class ArvoreBinariaDeBusca
{
private:
    No *raiz; // Ponteiro para a raiz da árvore

    // Método privado para realizar a inserção de um valor na árvore
    No *insercao(No *no, int valor)
    {
        // Se o nó é nulo, cria um novo nó com o valor
        if (no == NULL)
        {
            no = new No;
            no->info = valor;
            no->esq = NULL;
            no->dir = NULL;
        }
        // Se o valor é menor que o valor do nó, insere à esquerda
        else if (valor < no->info)
        {
            no->esq = insercao(no->esq, valor);
        }
        // Se o valor é maior ou igual, insere à direita
        else
        {
            no->dir = insercao(no->dir, valor);
        }
        return no;
    }

    // Método privado para realizar a remoção de um valor na árvore
    No *remocao(No *no, int valor)
    {
        // Se o nó é nulo, retorna nulo
        if (no == NULL)
        {
            return NULL;
        }
        // Se o valor é menor que o valor do nó, remove à esquerda
        else if (valor < no->info)
        {
            no->esq = remocao(no->esq, valor);
        }
        // Se o valor é maior que o valor do nó, remove à direita
        else if (valor > no->info)
        {
            no->dir = remocao(no->dir, valor);
        }
        // Se o valor é igual ao valor do nó, remove o nó
        else
        {
            // Se o nó não tem filhos, remove o nó
            if (no->esq == NULL && no->dir == NULL)
            {
                delete no;
                no = NULL;
            }
            // Se o nó tem apenas um filho, remove o nó e retorna o filho
            else if (no->esq == NULL)
            {
                No *aux = no;
                no = no->dir;
                delete aux;
            }
            // Se o nó tem apenas um filho, remove o nó e retorna o filho
            else if (no->dir == NULL)
            {
                No *aux = no;
                no = no->esq;
                delete aux;
            }
            // Se o nó tem dois filhos, troca o valor do nó com o maior valor da subárvore esquerda
            else
            {
                No *aux = no->esq;
                while (aux->dir != NULL)
                {
                    aux = aux->dir;
                }
                no->info = aux->info;
                aux->info = valor;
                no->esq = remocao(no->esq, valor);
            }
        }
        return no;
    }

    // Método privado para realizar o percurso pré-ordem na árvore
    void preOrdem(No *no)
    {
        // Se o nó não é nulo
        if (no != NULL)
        {
            // Imprime o valor do nó
            cout << no->info << ", ";
            // Chama recursivamente o percurso pré-ordem para o filho esquerdo
            preOrdem(no->esq);
            // Chama recursivamente o percurso pré-ordem para o filho direito
            preOrdem(no->dir);
        }
    }

    // Método privado para realizar o percurso em ordem na árvore
    void emOrdem(No *no)
    {
        // Se o nó não é nulo
        if (no != NULL)
        {
            // Chama recursivamente o percurso em ordem para o filho esquerdo
            emOrdem(no->esq);
            // Imprime o valor do nó
            cout << no->info << ", ";
            // Chama recursivamente o percurso em ordem para o filho direito
            emOrdem(no->dir);
        }
    }

public:
    // Construtor da classe
    ArvoreBinariaDeBusca()
    {
        raiz = NULL; // Inicializa a raiz como nula
    }

    // Método público para inserir um valor na árvore
    void insercao(int valor)
    {
        raiz = insercao(raiz, valor);
    }

    // Método público para remover um valor da árvore
    void remocao(int valor)
    {
        raiz = remocao(raiz, valor);
    }

    // Método público para realizar o percurso pré-ordem e imprimir na tela
    void preOrdem()
    {
        cout << "\n[";
        preOrdem(raiz);
        cout << "]" << endl;
    }

    // Método público para realizar o percurso em ordem e imprimir na tela
    void emOrdem()
    {
        cout << "\n[";
        emOrdem(raiz);
        cout << "]" << endl;
    }

    // Método público para realizar o percurso pós-ordem e imprimir na tela
    void posOrdem()
    {
        cout << "\n[";
        posOrdem(raiz);
        cout << "]" << endl;
    }
};