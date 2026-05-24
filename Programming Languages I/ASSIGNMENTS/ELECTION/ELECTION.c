/*

Trabalho de Linguagem de Programação I
Universidade Veiga de Almeida

Programa de Eleição

Caio Ronald Carlos da Silva
2026

*/

// 1 - BIBLIOTECAS NECESSÁRIAS

#include <stdio.h>

// 2 - VARIÁVEIS PARA REGISTRO DE CANDIDATOS E ALTERNATIVAS DE VOTOS

int candidato1    = 0;
int candidato2    = 0;
int candidato3    = 0;
int votosEmBranco = 0;
int votosNulos    = 0;
int fim           = 1;
int voto;
int vencedor;
int totalDeEleitores;

// 3 - FUNÇÃO PARA O RESULTADO

int resultado() {

    if (candidato1 > candidato2 && candidato1 > candidato3) {

        vencedor = 1;

    } else if (candidato2 > candidato1 && candidato2 > candidato3) {

        vencedor = 2;
    
    } else {
    
        vencedor = 3;
    
    };

    totalDeEleitores = candidato1    +
                       candidato2    +
                       candidato3    +
                       votosEmBranco +
                       votosNulos;

    printf("\nTotal de votos para o Candidato 1: %d.\n", candidato1);
    printf("Total de votos para o Candidato 2: %d.\n", candidato2);
    printf("Total de votos para o Candidato 3: %d.\n", candidato3);

    printf("\nTotal de votos em branco: %d.\n", votosEmBranco);
    printf("Total de votos nulos: %d.\n", votosNulos);

    printf("\nCandidato vencedor: Candidato %d\n", vencedor);
    printf("Total de Eleitores: %d\n", totalDeEleitores);

};

// 4 - FUNÇÃO PARA A VOTAÇÃO

int votacao() {

    printf("*Bem vindo ao Programa de Votação para as Eleições*\n");
    printf("\nTutorial:\n");
    printf("\nPara Votar no Candidato 1: Digite 1");
    printf("\nPara Votar no Candidato 2: Digite 2");
    printf("\nPara Votar no Candidato 3: Digite 3");
    printf("\nPara Votar em Branco:      Digite 4");
    printf("\nPara Votar Nulo:           Digite qualquer número após o 4\n");
    printf("\nDigite 0 para Encerrar a Votação e Ver o Resultado\n");

    do {
        
        printf("\nVote no Seu Candidato:\n");
        scanf("%d", &voto);

        switch (voto) {

            case 0:
            fim = 0;
            resultado();
            break;

            case 1:
            candidato1++;
            break;

            case 2:
            candidato2++;
            break;

            case 3:
            candidato3++;
            break;

            case 4:
            votosEmBranco++;
            break;

            default:
            votosNulos++;
            break;

        }

    } while (fim == 1);

};

// 5 - FUNÇÃO MAIN

int main () {

    votacao();

};