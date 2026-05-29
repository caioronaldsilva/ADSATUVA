/*

Universidade Veiga de Almeida
Trabalho de Linguagem de Programação I

Programa para Gestão de Estoque

Caio Ronald Carlos da Silva
2026

*/

// 1 - BIBLIOTECAS NECESSÁRIAS:
// stdio.h PARA LER E EXIBIR DADOS E
// string.h PARA MANIPULÇÃO DE STRINGS.

#include <stdio.h>
#include <string.h>

// 2 - struct PARA A MERCADORIA

typedef struct {

    char  nome[30];
    int   unidades;
    float precoUnitario;
    float valorDoEstoque;

} mercadoria;

// 3 - FUNÇÃO PARA ADICIONAR MERCADORIAS

int adicaoDeMercadorias() {

    mercadoria item;

    printf("Adicione o nome da mercadoria (até 30 caracteres):\n");
    scanf("%c", &item.nome);

    printf("Adicione a quantidade:\n");
    scanf("%d", &item.unidades);

    printf("Adicione o preço:\n");
    scanf("%f", &item.precoUnitario);

    item.valorDoEstoque = item.unidades * item.precoUnitario;

};

// 4 - FUNÇÃO PARA INICIAL DO PROGRAMA

int inicio() {

    printf("* Bem vindo ao Programa para Gestão de Estoque (feito em C) *\n");

    printf("\nEscolha a função:\n");

    printf("\nDigite 1 para Adição de Item ao Estoque.\n");
    prinft("Digite 2 para Remover um Item do Estoque.\n");
    printf("Digite 3 para ver o Relatório Geral.\n");

    escolherOpcao();

}

// 5 - FUNÇÃO PARA ESCOLHA DA FUNCIONALIDADE DESEJADA

int escolherOpcao() {

    int   opcao;

    printf("\nDigite sua opção:\n");
    scanf("%d", &opcao);

    if (opcao == 1) {

        adicionarMercadoria();
    
    } else if (opcao == 2) {

        removerMercadoria();

    } else if (opcao == 3) {

        verRelatorio();

    } else {

        printf("\nOpção inválida. Tente novamente!\n");
        escolherOpcao();

    }

};

int main() {

    inicio();

};