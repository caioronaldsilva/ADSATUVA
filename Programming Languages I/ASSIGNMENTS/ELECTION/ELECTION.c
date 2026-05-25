/*

Universidade Veiga de Almeida
Trabalho de Linguagem de Programação I

Programa para Apuração de Eleição

Caio Ronald Carlos da Silva
Araruama - RJ
2026

*/

// 1 - BIBLIOTECAS NECESSÁRIAS:
// O stdio.h SERVE PARA LER E EXIBIR DADOS.
// USAREMOS A BIBLIOTECA PARA A INTERAÇÃO COM O USUÁRIO.

#include <stdio.h>

// 2 - VARIÁVEIS QUE SERÃO USADAS :
// DECLAREI TODAS AS VARIÁVEIS NO MESMO LUGAR
// PARA MELHORAR A ORGANIZAÇÃO DO CÓDIGO.

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

// 3 - FUNÇÃO PARA A APURAÇÃO DA VOTAÇÃO:
// AQUI, VERIFICAMOS QUEM É O VENCEDOR OU SE HÁ EMPATE
// ATRAVÉS DA COMPARAÇÃO ENTRE OS VOTOS DE CADA CANDIDATO.
// EM SEGUIDA, DEFINIMOS O TOTAL DE ELEITORES SOMANDO OS
// VOTOS DE CADA CANDIDATO, OS VOTOS EM BRANCO E OS NULOS.
// USAMOS printf PARA MOSTRAR AS INFORMAÇÕES AO USUÁRIO

void resultado() {

    if (candidato1 > candidato2 && candidato1 > candidato3) {

        vencedor = 1;

    } else if (candidato2 > candidato1 && candidato2 > candidato3) {

        vencedor = 2;
    
    } else if (candidato3 > candidato1 && candidato3 > candidato2) {
    
        vencedor = 3;
    
    } else {

        vencedor = 0;

    }

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

}

// 4 - FUNÇÃO PARA A VOTAÇÃO:
// PARA MELHORAR O USO DO PROGRAMA, EU FIZ UM PEQUENO TUTORIAL.
// APÓS O VOTO DO USUÁRIO, O scanf GUARDA O DADO NA VARIÁVEL
// (É FEITA UMA FILTRAGEM DO VOTO PARA NÃO PERMITIR CARACTERES INVÁLIDOS).
// O SWITCH ENCERRA A VOTAÇÃO OU GUARDA O VOTO NA VARIÁVEL CORRETA.

void votacao() {

    printf("* Bem vindo ao Programa de Votação e Apuração para Eleições (feito em C) *\n");
    printf("\nTutorial:\n");
    printf("\nDigite 1 para Votar no Candidato 1");
    printf("\nDigite 2 para Votar no Candidato 2");
    printf("\nDigite 3 para Votar no Candidato 3");
    printf("\nDigite 4 para Votar em Branco");
    printf("\nDigite 0 para Encerrar a Votação e Ver o Resultado\n");

    printf("\nObs.: Caso digite uma opção inexistente (ex.: 5), seu voto será anulado!\n");

    while (fim == 1) {
        
        printf("\nVote no Seu Candidato:\n");
        
        while (scanf("%d%c", &voto, &votoProtI) != 2 || votoProtI != '\n') {

            while ((votoProtII = getchar()) != '\n' && votoProtII != EOF);
            printf("\nEssa tentativa não é válida! Vote novamente:\n");

        }

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

    }

}

// 5 - FUNÇÃO MAIN:
// CHAMA A FUNÇÃO votacao() PARA INICIAR A LÓGICA DO PROGRAMA.

int main () {

    votacao();
    return 0;

}