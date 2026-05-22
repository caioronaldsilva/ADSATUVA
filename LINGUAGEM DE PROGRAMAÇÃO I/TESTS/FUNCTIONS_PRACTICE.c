// FUNCTIONS MUST EXIST BEFORE THEY ARE CALLED
// \n CREATES A NEW LINE
// & PASSES THE VARIABLE ADDRESS TO scanf

#include <stdio.h>

int soma(int a, int b) {
    
    int c = a + b;
    return c;
    
}

int subt(int a, int b) {
    
    int c = a - b;
    return c;
    
}

int mult(int a, int b) {
    
    int c = a * b;
    return c;
    
}

float divs(int a, int b) {

    float c = (float)a / b;
    return c;
}

int rest(int a, int b) {

    int c = a % b;
    return c;

}

float medi(int a, int b) {

    float c = (a + b) / 2.0;
    return c;
    
}

int main() {
    
    int a, b;
    
    printf("Digite o Valor para a:");
    scanf("%d", &a);
    printf("Digite o Valor para b:");
    scanf("%d", &b);
    
    printf("Soma: %d\n", soma(a, b));
    printf("Subtração: %d\n", subt(a, b));
    printf("Multiplicação: %d\n", mult(a, b));

    if (b == 0) {

        printf("Não é possível dividir por 0!\n");

    } else {

        printf("Divisão: %.2f\n", divs(a, b));
        printf("Resto: %d\n", rest(a, b));

    }

    printf("Média: %.2f\n", medi(a, b));
    
    return 0;
    
}