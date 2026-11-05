#include <stdio.h>
long long bagisetengah(long long N){
    if (N == 0) return 0;

    return 1 + bagisetengah(N/2);
}

int main(){
    long long N;
    scanf("%lld", &N);

    printf("%lld", bagisetengah(N));
    return 0;
}