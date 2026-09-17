#include <stdio.h>

int main() {
    int A, B;
    int hasilOR, shiftR;
    scanf("%d %d", &A, &B);
    hasilOR= A | B;
    shiftR = hasilOR >> 2;
    
    printf("Hasil: %d\n", shiftR);
    (shiftR % 2 == 1) ? printf("Status: Ganjil") : printf("Status: Genap");
}