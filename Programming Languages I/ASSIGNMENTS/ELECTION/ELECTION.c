/*

Trabalho de Linguagem de Programação I
Universidade Veiga de Almeida

Programa de Eleição

Caio Ronald Carlos da Silva
2026

*/

// 1 - BIBLIOTECAS NECESSÁRIAS

#include <stdio.h>

// 2 - VARIÁVEIS QUE SERÃO USADAS EM TODO O PROGRAMA

int candidato1    = 0;
int candidato2    = 0;
int candidato3    = 0;
int votosEmBranco = 0;
int votosNulos    = 0;
int fim           = 1;
int voto;
int vencedor;
int totalDeEleitores;
int votoProtII;
char votoProtI;

// 3 - FUNÇÃO PARA O RESULTADO

int resultado() {

    if (candidato1 > candidato2 && candidato1 > candidato3) {

        vencedor = 1;

    } else if (candidato2 > candidato1 && candidato2 > candidato3) {

        vencedor = 2;
    
    } else if (candidato3 > candidato1 && candidato3 > candidato2) {
    
        vencedor = 3;
    
    } else {

        vencedor = 0;

    };

    totalDeEleitores = candidato1    +
                       candidato2    +
                       candidato3    +
                       votosEmBranco +
                       votosNulos;

    printf("\n* Resultado das Eleições *\n");

    printf("\nTotal de votos para o Candidato 1: %d.\n", candidato1);
    printf("Total de votos para o Candidato 2: %d.\n", candidato2);
    printf("Total de votos para o Candidato 3: %d.\n", candidato3);

    printf("\nTotal de votos em Branco: %d.\n", votosEmBranco);
    printf("Total de votos Nulos: %d.\n", votosNulos);

    printf("\nTotal de Eleitores: %d\n", totalDeEleitores);

    if (vencedor == 0) {

        printf("\nResultado: Houve um Empate!\n");

    } else {

        printf("\nResultado: O Candidato %d venceu!\n", vencedor);

    }

};

// 4 - FUNÇÃO PARA A VOTAÇÃO

int votacao() {

    printf("* Bem vindo ao Programa de Votação para as Eleições (feito em C) *\n");
    printf("\nTutorial:\n");
    printf("\nDigite 1 para Votar no Candidato 1");
    printf("\nDigite 2 para Votar no Candidato 2");
    printf("\nDigite 3 para Votar no Candidato 3");
    printf("\nDigite 4 para Votar em Branco");
    printf("\nDigite 0 para Encerrar a Votação e Ver o Resultado\n");

    printf("\nObs.: Caso digite uma opção inexistente (ex.: 5), seu voto será anulado!\n");

    do {
        
        printf("\nVote no Seu Candidato:\n");
        
        while (scanf("%d%c", &voto, &votoProtI) != 2 || votoProtI != '\n') {

            while ((votoProtII = getchar()) != '\n' && votoProtII != EOF);
            printf("\nEssa tentativa não é válida! Vote novamente:\n");

        };

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