// IN "C", THE PARAMETERS OF "FOR" ARE SEPARED BY ";"

#include <stdio.h>

int main() {
    
    int mat[3][5];
    int lin, col;

    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col <5; col++) {

            printf("Choose a value:");
            scanf("%d", &mat[lin][col]);

        }
    }

    printf("\nThe values in the matrix are:\n");
    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 5; col++)
        printf("Mat[%d][%d]: %d\n", lin, col, mat[lin][col]);
    }        

    return 0;

}