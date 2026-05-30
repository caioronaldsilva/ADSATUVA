/*

Universidade Veiga de Almeida
Trabalho de Linguagem de Programação I

Programa para Gestão de Estoque

Caio Ronald Carlos da Silva
2026

*/

// 1 - BIBLIOTECAS NECESSÁRIAS:
// stdio.h PARA LER E EXIBIR DADOS,
// string.h PARA MANIPULÇÃO DE STRINGS e
// stdlib.h PARA ALGUMAS FUNÇÕES QUE GERENCIAM A MEMÓRIA.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 2 - PROTÓTIPO DA FUNÇÃO inicio():
// inicio() É DECLARADA LOGO ANTES DA main(),
// É NECESSÁRIO UM PROTÓTIPO DA FUNÇÃO PARA QUE O
// COMPILADOR SAIBA QUE ELA EXISTE
// (JÁ QUE É CHAMADA EM FUNÇÕES ANTERIORES A ELA).

void inicio();

// 3 - struct PARA A MERCADORIA E VARIÁVEIS GLOBAIS:
// IMPORTANTE DECLARAR ANTES DE TUDO PARA USARMOS
// EM MAIS DE UMA FUNÇÃO.

typedef struct {

    char  nome[31];
    int   id;
    int   unidades;
    float valorUnitario;
    float valorTotal;

} mercadoria;
  mercadoria *item;

int quantidadeDeMercadorias;

// 4 - FUNÇÃO PARA ADICIONAR MERCADORIAS:
// ADICIONAMOS AS MERCADORIAS ATRAVÉS DE UMA
// FUNÇÃO ROBUSTA, EVITANDO ERROS NOS INPUTS.
// DESTAQUE PARA O buffer clean, malloc, fgets E O size_t.

void adicionarMercadorias() {

    int  quantMercProtII;
    char quantMercProtI;

    printf("\nQuantas mercadorias você quer adicionar?\n");
    while (scanf("%d%c", &quantidadeDeMercadorias, &quantMercProtI) != 2 || quantMercProtI != '\n') {
        while ((quantMercProtII = getchar()) != '\n' && quantMercProtII != EOF);
        printf("\nEsta opção não é válida! Digite novamente:\n");
    };

    item = malloc(quantidadeDeMercadorias * sizeof(mercadoria));

    for (int indice = 0; indice < quantidadeDeMercadorias; indice++) {

        printf("\nAdicione o nome da mercadoria (até 30 caracteres):\n");
        fgets(item[indice].nome, sizeof(item[indice].nome), stdin);

        size_t enter = strcspn(item[indice].nome, "\n");
        item[indice].nome[enter] = '\0';

        item[indice].id = indice + 1;

        int  quantItemProtII;
        char quantItemProtI;

        printf("\nAdicione a quantidade:\n");
        while (scanf("%d%c", &item[indice].unidades, &quantItemProtI) != 2 || quantItemProtI != '\n') {
            while ((quantItemProtII = getchar()) != '\n' && quantItemProtII != EOF);
            printf("\nEsta opção não é válida! Digite novamente:\n");
        };

        int  valorItemProtII;
        char valorItemProtI;

        printf("\nAdicione o preço:\n");
        while (scanf("%f%c", &item[indice].valorUnitario, &valorItemProtI) != 2 || valorItemProtI != '\n') {
            while ((valorItemProtII = getchar()) != '\n' && valorItemProtII != EOF);
            printf("\nEste valor não é válido! Digite novamente:\n");
        };

        item[indice].valorTotal = item[indice].unidades * item[indice].valorUnitario;

    }

    if (quantidadeDeMercadorias == 1) {
        printf("\nMercadoria adicionada!\n");
    } else {
        printf("\nMercadorias adicionadas!\n");
    }

    inicio();

};

// 5 - FUNÇÂO PARA REMOVER UMA MERCADORIA:
// ACRESCENTEI UMA FUNÇÃO PARA REMOVER MERCADORIAS,
// TORNANDO O PROGRAMA MAIS COMPLETO.
// DESTAQUE PARA O array shifting E A reindexação.

void removerMercadorias() {

    if (quantidadeDeMercadorias == 0) {

        printf("\nAinda não há nenhuma mercadoria no estoque!\n");

    } else {

        for (int indice = 0; indice < quantidadeDeMercadorias; indice++) {
            printf("\n%d - %s\n", item[indice].id, item[indice].nome);
        };

        int idForDelete;
        printf("\nQual mercadoria você deseja remover?\n");
        scanf("%d", &idForDelete);
        idForDelete = idForDelete - 1;

        for (int indice = idForDelete; indice < quantidadeDeMercadorias - 1; indice++) {
            item[indice] = item[indice + 1];
        } 

        quantidadeDeMercadorias--;

        for (int indice = 0; indice < quantidadeDeMercadorias; indice++) {
            item[indice].id = indice + 1;
        }

        printf("\nMercadoria removida!\n");

    }

    inicio();

};

// 6 - FUNÇÃO PARA CALCULAR O VALOR TOTAL DO ESTOQUE:
// for PARA SOMAR OS VALORES TOTAIS DE TODAS AS MERCADORIAS.

float valorTotalDoEstoque() {

    float valorTotalDasMercadorias = 0;

    for (int indice = 0; indice < quantidadeDeMercadorias; indice++) {
        valorTotalDasMercadorias += item[indice].valorTotal;
    };

    return valorTotalDasMercadorias;

};

// 7 - FUNÇÃO PARA MOSTRAR O RELATÒRIO:
// for PARA MOSTRAR TODAS AS MERCADORIAS E SUAS
// INFORMAÇÕES, ALÉM DO VALOR TOTAL DO ESTOQUE.

void verRelatorio () {

    printf("\n* Relatório do Estoque *\n");

    for (int indice = 0; indice < quantidadeDeMercadorias; indice++) {
        printf("\n%s:\n%d Unidades | R$ %.2f Cada\n", item[indice].nome, item[indice].unidades, item[indice].valorUnitario);
    };

    printf("\nR$ %.2f de valor total em estoque.\n", valorTotalDoEstoque());

    inicio();

};

// 8 - FUNÇÃO PARA ESCOLHA DA FUNCIONALIDADE DESEJADA
// if ... else PARA O USUÁRIO ESCOLHER ENTRE A FUNÇÃO DESEJADA,
// COM DESTAQUE PARA A VALIDAÇÃO DO INPUT, COMO A adicionarMercadoria().

void escolherOpcao() {

    int  opcao;
    int  opcaoProtII;
    char opcaoProtI;

    printf("\nDigite sua opção:\n");
    while (scanf("%d%c", &opcao, &opcaoProtI) != 2 || opcaoProtI != '\n') {
        while ((opcaoProtII = getchar()) != '\n' && opcaoProtII != EOF);
        printf("\nEsta opção não é válida! Escolha novamente:\n");
    };

    if (opcao        == 1) {
        adicionarMercadorias();
    } else if (opcao == 2) {
        removerMercadorias();
    } else if (opcao == 3) {
        verRelatorio();
    } else if (opcao == 0) {
        free(item);
        item = NULL;
        exit(0);
    } else {
        printf("\nOpção inválida. Tente novamente!\n");
        escolherOpcao();
    }

};

// 9 - FUNÇÃO PARA INICIAL DO PROGRAMA:
// UM MENU DE OPÇÕES PARA O USUÁRIO SABER
// COMO USAR O PROGRAMA.

void inicio() {

    printf("\nEscolha a função:\n");

    printf("\nDigite 1 para Adicionar Mercadorias ao Estoque.\n");
    printf("Digite 2 para Remover uma Mercadoria do Estoque.\n");
    printf("Digite 3 para ver o Relatório Geral.\n");
    printf("Digite 0 para Sair.\n");

    escolherOpcao();

};

// 10 - FUNÇÃO MAIN:
// FUNÇÃO PADRÃO DA LINGUAGEM C.
// 

int main() {

    printf("* Bem vindo ao Programa para Gestão de Estoque (feito em C) *\n");
    inicio();

    return 0;

};