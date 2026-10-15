#include <stdio.h>

int main(){
    int R, C;
    long long K;
    scanf("%d %d %lld", &R, &C, &K);

    int A[100][100];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            scanf("%d", &A[i][j]);
        }
    }

    int atas = 0, bawah = R - 1, kiri = 0, kanan = C - 1;
    long long paraDebu = 0;
    int hopp = 0;

    int buatsimpenhasildisini[100*100];
    int count = 0;

    while(atas <= bawah && kiri <= kanan && hopp == 0){
        //kanan sek
        for(int a = kiri; a <= kanan; a++){
            buatsimpenhasildisini[count++] = A[atas][a];
            paraDebu += A[atas][a];
                if (paraDebu >= K){
                hopp = 1;
                break;
                }
            }
        atas++;
        if(hopp == 1) break;

        //////////// bawah
        for(int b = atas; b <= bawah; b++){
                buatsimpenhasildisini[count++] = A[b][kanan];
                paraDebu += A[b][kanan];
                if (paraDebu >= K){
                hopp = 1;
                break;
                }
            }
        kanan--;
        if(hopp == 1) break;

        ///////////// kiri
        if(atas <= bawah){
            for(int c = kanan; c >= kiri; c--){
                buatsimpenhasildisini[count++] = A[bawah][c];
                paraDebu += A[bawah][c];
                if (paraDebu >= K){
                hopp = 1;
                break;
                }
            }
        }
        bawah--;
        if(hopp == 1) break;

        ///////////// atas bos q
        if(kiri <= kanan){
                for(int d = bawah; d >= atas; d--){
                buatsimpenhasildisini[count++] = A[d][kiri];
                paraDebu += A[d][kiri];
                if (paraDebu >= K){
                hopp = 1;
                break;
                }
            }
        }
        kiri++;
        if(hopp == 1) break;
    }

    for(int i = 0; i < count; i++){
        printf("%d\n", buatsimpenhasildisini[i]);
    }
    
    printf("%lld", paraDebu);

    return 0;
}