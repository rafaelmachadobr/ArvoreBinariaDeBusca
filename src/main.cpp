#include <iostream>
#include "abb.cpp"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ArvoreBinariaDeBusca arvore;
    int opcao, valor, escolha;

    cout << "Árvore Binária de Busca\n";

    do
    {
        cout << "\nEscolha uma opção:\n\n";
        cout << "1 - Inserção\n";
        cout << "2 - Remoção\n";
        cout << "3 - Percursos\n";
        cout << "0 - Sair\n";
        cout << "\nOpção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\nDigite o valor a ser inserido: ";
            cin >> valor;
            arvore.insercao(valor);
            break;
        case 2:
            cout << "\nDigite o valor a ser removido: ";
            cin >> valor;
            arvore.remocao(valor);
            break;
        case 3:
        {
            cout << "\nEscolha um percurso:\n";
            cout << "1 - Pré-Ordem\n";
            cout << "2 - Em Ordem\n";
            cout << "3 - Pós-Ordem\n";
            cout << "Opção: ";
            cin >> escolha;

            switch (escolha)
            {
            case 1:
                arvore.preOrdem();
                break;
            case 2:
                arvore.emOrdem();
                break;
            case 3:
                arvore.posOrdem();
                break;
            default:
                cout << "\nOpção inválida!\n";
            }
            break;
        }
        case 0:
            cout << "\nSaindo...\n";
            break;
        default:
            cout << "\nOpção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}