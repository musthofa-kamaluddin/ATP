#include <stdio.h>

struct timfutsal {
    char nama[21];
    int menang, seri, kalah;
    int cetak, masuk;
}; 

int main(){
    int n;
    struct timfutsal tim[100];

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s %d %d %d %d %d", tim[i].nama, &tim[i].menang, &tim[i].seri, &tim[i].kalah, &tim[i].cetak, &tim[i].masuk);
    }

    int pemenangcoy = 0;
    for(int i = 1; i < n; i++){
        if((tim[i].menang * 3 + tim[i].seri) > (tim[pemenangcoy].menang * 3 + tim[pemenangcoy].seri)){
            pemenangcoy = i;
        }else if((tim[i].menang * 3 + tim[i].seri) == (tim[pemenangcoy].menang * 3 + tim[pemenangcoy].seri) && (tim[i].cetak - tim[i].masuk) > (tim[pemenangcoy].cetak - tim[pemenangcoy].masuk)){
            pemenangcoy = i;
        }
    }

    printf("Juara: %s\n", tim[pemenangcoy].nama);
    printf("Poin: %d\n", tim[pemenangcoy].menang * 3 + tim[pemenangcoy].seri);
    printf("Selisih gol: %d\n", tim[pemenangcoy].cetak - tim[pemenangcoy].masuk);
    return 0;
}