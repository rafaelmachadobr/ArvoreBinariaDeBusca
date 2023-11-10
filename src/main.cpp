#include <iostream>
#include "abb.cpp"
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configuração da localidade para exibição de caracteres acentuados

    ArvoreBinariaDeBusca arvore; // Cria uma instância da classe ArvoreBinariaDeBusca
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
            arvore.insercao(valor); // Chama o método de inserção da árvore
            break;
        case 2:
            cout << "\nDigite o valor a ser removido: ";
            cin >> valor;
            arvore.remocao(valor); // Chama o método de remoção da árvore
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
                arvore.preOrdem(); // Chama o método de percurso pré-ordem da árvore
                break;
            case 2:
                arvore.emOrdem(); // Chama o método de percurso em ordem da árvore
                break;
            case 3:
                arvore.posOrdem(); // Chama o método de percurso pós-ordem da árvore
                break;
            default:
                cout << "\nOpção inválida!\n";
            }
            break;
        }
        case 0:
            cout << "\nObrigado por utilizar o programa!";
            break;
        default:
            cout << "\nOpção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}