#include <stdio.h>

int main() {
    long U;
    int H, M, C;
    int limitBeli, sisaUang;
    long long cashback, uangCashback, total;
    scanf("%ld %d %d %d", &U, &H, &M, &C);
    limitBeli = U / H;
    sisaUang = U % H;
    cashback = limitBeli / M;
    uangCashback = cashback * C;
    total = sisaUang + uangCashback;
    // printf("%d %d %lld %lld %lld\n" ,limitBeli, sisaUang, cashback, uangCashback, total); mmf ya kak buat debugging
    printf("Hendra mendapatkan %ld liter bensin dan sisa uang %lld Euro.", limitBeli, total);

}