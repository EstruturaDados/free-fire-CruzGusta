#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool ordenadoPorNome = false;
int totalItens = 0; //zera os itens da mochila

// para substituir os numeros magicos
enum Criterio{
    NOME =1, TIPO , PRIORIDADE
};

//criação da struct item:
struct Item{

    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;

};

//criação do item "mochila"
struct Item mochila[10];

//Função para adicionar item
void adicionar(){

    if(totalItens >= 10){
        printf("Mochila cheia, não da para adicinar mais.\n");
    }else{
        printf("Digite o item que deseja adicionar na mochila: \n");
        scanf("%s", mochila[totalItens].nome);

        printf("Digite o tipo do item: \n");
        scanf("%s", mochila[totalItens].tipo);

        printf("Digite a quantidade: \n");
        scanf("%d", &mochila[totalItens].quantidade);

        printf("Digite a prioridade: \n");
        scanf("%d", &mochila[totalItens].prioridade);

        //if para evitar numeros que não sejam de 1 a 5
        if(mochila[totalItens].prioridade > 5 || mochila[totalItens].prioridade < 1){ //vrificação 
            
            printf("a prioridade é de 1 a 5. \n");
            return;
        }
        totalItens++;
        ordenadoPorNome = false;
        
    }
 
}

//funcçao de listar itens
void listar(){
    for(int i = 0 ; i < totalItens; i++){
        
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d \n", mochila[i].quantidade);
        printf("Prioridade: %d\n\n", mochila[i].prioridade);

    }
}

//função para remover
void remover(){
    //verifica se tem algum item ali no inventario
    if(totalItens == 0){
        printf("Não há nada a ser removido.\n");
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
                 ordenadoPorNome = false;
                break;
            }
        }
    }
    
}

//função para buscar de forma binaria (nivel mestre)
void buscarBinario(){

    if(!ordenadoPorNome){
        printf("A mochila precisa estar ordenada por nome. \n");
        return;
    }

    char nome[30];

    printf("Digite o nome do item: \n");
    scanf("%s", nome);

    int inicio = 0;
    int fim = totalItens -1;

    while(inicio <= fim){

        int meio = (inicio + fim) / 2;
        int resultado = strcmp(mochila[meio].nome, nome);

        if(resultado == 0){

            printf("Item encontrado!\n");
            printf("nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            return;
        }
        else if(resultado < 0){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
    printf("Item não encontrado. \n");
}

//funçao de ordenar 
void ordenar(enum Criterio criterio){

    int comparacoes = 0;

    for(int i = 1; i < totalItens; i++ ){

        struct Item atual = mochila[i];
        int j = i - 1;
        
        while(j >= 0){

            comparacoes++;
            int resultado = 0;

            if(criterio == NOME){
                resultado = strcmp(mochila[j].nome, atual.nome);
            }
            else if(criterio == TIPO){
                resultado = strcmp(mochila[j].tipo, atual.tipo);
            }
            else if(criterio == PRIORIDADE){
                resultado = mochila[j].prioridade - atual.prioridade;
            }

            if (resultado > 0){

                mochila[j + 1] = mochila[j];
                j--;

            }else{
                break;
            }

        }

        mochila[j + 1] = atual;
    }

    printf("ordenação concluida com sucesso!!!\n");
    printf("Comparações realizada; %d\n", comparacoes);

    if(criterio == NOME){
        ordenadoPorNome = true;       
    }else{
        ordenadoPorNome = false;
    }
}


int main(){

    int opcao;

    do{
        printf("Quantidade de itens na mochila: %d\n\n", totalItens);
        printf("###### MENU ######\n");
        printf(" 1 - Adicionar item\n");
        printf(" 2 - Remover item\n");
        printf(" 3 - Listar item\n");
        printf(" 4 - Buscar item (Busca binaria)\n");
        printf(" 5 - Ordernar itens\n");
        printf(" 0 - Sair\n");

        printf("Escolha uma opção: \n\n");
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

            case 4:
            buscarBinario();
            break;

            case 5:{
                 int criterio;
            printf("Escolha o parametro: \n");
            printf("1 - Nome\n");
            printf("2 - Tipo\n");
            printf("3 - Prioridade\n");
            scanf("%d", &criterio);

            ordenar(criterio);

            break;
            }
           

            case 0:
            printf("saindo...");
            break;

            default:
            printf("Opção invalida\n");
        }

    }while(opcao != 0);


    return 0;
}