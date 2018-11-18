#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>

void cabecalho() {
    printf("\n\nEscolha a opção desejada:\n\n");
    printf("1 - Inserir um novo cadastro\n");
    printf("2 - Mostrar contatos cadastros\n");
    printf("0 - Encerrar\n\n");
}

void clear() {
    //system("cls");
    system("clear");
}

void pause_and_clear() {
    //print("\n\n");
    //system("pause");
    //system("cls");
    system("read -n1 -r -p \"\n\nPressione qualquer tecla para continuar...\" key");
    clear();
}

struct cadastro_agenda {
        int codigo, numero;
        char nome[30], telefone[20], endereco[100], complemento[50];
};



int main() {
    //setlocale(LC_ALL, "Portuguese");
    
    struct cadastro_agenda agenda[5];
    int opcao, posicao, j;

    posicao = 0;
    opcao = -1;

    clear();
    printf("\n\n***** BEM VINDO A SUA AGENDA ELETRÔNICA *****\n\n");

    while (opcao != 0) {
        cabecalho();
        scanf("%d", &opcao);
        clear();
        
        switch (opcao) {
            case 1 :
                if (posicao > 4) {
                    printf("\n\n\n        Agenda Lotada!        \n\n\n");
                    pause_and_clear();
                } else {
                    agenda[posicao].codigo = posicao + 1;
                    printf("\n\n        Informe o %dº contato:       \n\n", posicao + 1);
                    printf("\nInsira o nome: ");
                    getchar();
                    fgets(agenda[posicao].nome, sizeof(agenda[posicao].nome), stdin);
                    printf("Insira o telefone: ");
                    fgets(agenda[posicao].telefone, sizeof(agenda[posicao].telefone), stdin);
                    printf("Insira o endereço: ");
                    fgets(agenda[posicao].endereco, sizeof(agenda[posicao].endereco), stdin);
                    printf("Número: ");
                    scanf("%d", &agenda[posicao].numero);
                    getchar();
                    printf("Complemento: ");
                    fgets(agenda[posicao].complemento, sizeof(agenda[posicao].complemento), stdin);
                    posicao++;
                    clear();
                }
                break;
            case 2 :
                if (posicao <= 0) {
                    printf("\n\n\n        Agenda Vazia!        \n\n\n");
                } else { 
                    printf("\n\nContatos cadastrados:\n\n");
                    for (j = 0; j < posicao; j++) {
                        printf("\nCódigo: %d\n", agenda[j].codigo);
                        printf("Nome: %s", agenda[j].nome);
                        printf("Telefone: %s", agenda[j].telefone);
                        printf("Endereço: %s", agenda[j].endereco);
                        printf("Número: %d\n", agenda[j].numero);
                        printf("Complemento: %s", agenda[j].complemento);
                    }
                }
                pause_and_clear();
                break;
            case 0 :
                break;
            default :
                printf("\n\n\n        Erro: Opção inválida!        \n\n\n");
                pause_and_clear();
                break;
        }
    }

    clear();

    printf("\n\n\n        Até mais!        \n\n\n");

    return 0;
}