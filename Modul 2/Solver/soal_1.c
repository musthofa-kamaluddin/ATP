#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int A[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int target = 7;
    int krg_besi = 0, lebih_besi = 0;
    int krg_emas = 0, lebih_emas = 0;
    for(int i = 0; i < N; i++){

        int x = i + 1;
        int isprime = 1;
        if(x <= 1){
            isprime = 0;
        }else{
            for(int k = 2;k*k <= x; k++){
                if(x % k == 0){
                    isprime = 0;
                    break;
                }
            }
        }
        int selisih = A[i] - target;

        if (isprime){
            if(selisih > 0){
                lebih_emas += selisih;
            }else{
                krg_emas += (-selisih);
            }
        }else{
            if(selisih > 0){
                lebih_besi += selisih;
            }else{
                krg_besi += (-selisih);
            }
        }
    }

    int besi = krg_besi - lebih_besi;
    int emas = krg_emas - lebih_emas;

    if(besi < 0) besi = 0;
    if(emas < 0) emas = 0;

    int total = besi + emas;

    long long wang = (besi * 500000) + (emas * 3000000);
    printf("%d %lld", total, wang);

}