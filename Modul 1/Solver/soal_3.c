#include <stdio.h>

int main() {
    int d;
    long long n, T, K, J, S;
    long long kwakMakanAwal, kwikMakanAwal;

    scanf("%d %lld", &d, &n);
    scanf("%lld %lld %lld %lld", &T, &K, &J, &S);
    long long C = J + S;
    int pemesanan = n % 7;
    int pesta = (d - pemesanan + 7) % 7;

    if(pesta >= 1 && pesta <= 5){
        kwakMakanAwal = (C+1) / 2;
        kwikMakanAwal = C / 2;
    }else{
        kwikMakanAwal = (C+1) / 2;
        kwakMakanAwal = C / 2;
    }

    long long totalKwak = kwakMakanAwal + T;
    long long totalKwik = kwikMakanAwal + K;
    if(totalKwak > totalKwik){
        printf("Kwak %lld", totalKwak);
    }else if(totalKwak < totalKwik){
        printf("Kwik %lld", totalKwik);
    }else{
        printf("Sama %lld", totalKwik);
    }

}