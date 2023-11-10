#include <iostream>

using namespace std;

struct No
{
    int info;
    No *esq;
    No *dir;
};

class ArvoreBinariaDeBusca
{
private:
    No *raiz;

    No *insercao(No *no, int valor)
    {
        if (no == NULL)
        {
            no = new No;
            no->info = valor;
            no->esq = NULL;
            no->dir = NULL;
        }
        else if (valor < no->info)
        {
            no->esq = insercao(no->esq, valor);
        }
        else
        {
            no->dir = insercao(no->dir, valor);
        }
        return no;
    }

    No *remocao(No *no, int valor)
    {
        if (no == NULL)
        {
            return NULL;
        }
        else if (valor < no->info)
        {
            no->esq = remocao(no->esq, valor);
        }
        else if (valor > no->info)
        {
            no->dir = remocao(no->dir, valor);
        }
        else
        {
            if (no->esq == NULL && no->dir == NULL)
            {
                delete no;
                no = NULL;
            }
            else if (no->esq == NULL)
            {
                No *aux = no;
                no = no->dir;
                delete aux;
            }
            else if (no->dir == NULL)
            {
                No *aux = no;
                no = no->esq;
                delete aux;
            }
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

    void preOrdem(No *no)
    {
        if (no != NULL)
        {
            cout << no->info << ", ";
            preOrdem(no->esq);
            preOrdem(no->dir);
        }
    }

    void emOrdem(No *no)
    {
        if (no != NULL)
        {
            emOrdem(no->esq);
            cout << no->info << ", ";
            emOrdem(no->dir);
        }
    }

    void posOrdem(No *no)
    {
        if (no != NULL)
        {
            posOrdem(no->esq);
            posOrdem(no->dir);
            cout << no->info << ", ";
        }
    }

public:
    ArvoreBinariaDeBusca()
    {
        raiz = NULL;
    }

    void insercao(int valor)
    {
        raiz = insercao(raiz, valor);
    }

    void remocao(int valor)
    {
        raiz = remocao(raiz, valor);
    }

    void preOrdem()
    {
        cout << "\n[";
        preOrdem(raiz);
        cout << "]" << endl;
    }

    void emOrdem()
    {
        cout << "\n[";
        emOrdem(raiz);
        cout << "]" << endl;
    }

    void posOrdem()
    {
        cout << "\n[";
        posOrdem(raiz);
        cout << "]" << endl;
    }
};