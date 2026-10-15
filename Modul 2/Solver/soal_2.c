#include <stdio.h>

int main(){
    int R, C;

    scanf("%d %d", &R, &C);
    int A[100][100];

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    // printf("Matriks awal:\n");
    // for(int i = 0; i < R; i++){
        //     for(int j = 0; j < C; j++){
            //         printf("%d", A[i][j]);
            //         if(j < C-1) printf(" ");
    //     }
    //     printf("\n");
    // }
    
    // printf("\n");
    // printf("Matriks transpose:\n");
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R; j++){
            printf("%d", A[R - 1 - j][i]);
            if(j < R-1) printf(" ");
        }
        printf("\n");
    }
}