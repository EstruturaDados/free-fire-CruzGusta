#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criação da struct item:
struct Item {

    char nome[30];
    char tipo[20];
    int quantidade;

};

//criação do item "mochila"
struct Item mochila[10];
int totalItens = 0; //zera os itens da mochila

//Função para adicionar item
void adicionar(){

    printf("Digite o item que deseja adicionar na mochila: \n");
    scanf("%s", mochila[totalItens].nome);

    printf("Digite o tipo do item: \n");
    scanf("%s", mochila[totalItens].tipo);

    printf("Digite a quantidade: \n");
    scanf("%d", &mochila[totalItens].quantidade);

    totalItens++;

}

//funcçao de listar itens
void listar(){
    for(int i = 0 ; i < totalItens; i++){
        
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d \n\n", mochila[i].quantidade);

    }
}

//função para remover
void remover(){
    //verifica se tem algum item ali no inventario
    if(totalItens == 0){
        printf("Não há nada a sr removido.\n");
    }else{
        char nome[30];

        printf("Qual item deseja remover ?\n");
        scanf("%s", nome);

        for(int i = 0; i < totalItens; i++){ //percorre a lista

            if(strcmp(mochila[i].nome, nome) == 0){ //verifica se é verdadeiramente igual o item

                for(int j = i; j < totalItens - 1; j++){ //empurra a lista no lugar do item removido
                mochila[j] = mochila[j + 1];
                }

                 totalItens--;
                break;
            }
        }
    }
    
}

int main(){

    int opcao;

    do{

        printf("###### MENU ######\n");
        printf(" 1 - Adicionar item\n");
        printf(" 2 - Remover item\n");
        printf(" 3 - Listar item\n");
        printf(" 0 - Sair\n");

        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
            adicionar();
            break;

            case 2:
            remover();
            break;

            case 3:
            listar();
            break;

            case 0:
            printf("saindo...");
            break;

            default:
            printf("Opção invalida\n");
        }

    }while(opcao != 0);


    return 0;
}