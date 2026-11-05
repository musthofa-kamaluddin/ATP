#include <stdio.h>

////char array buat  list tim gooners (jirlah)
char member[8][10] = {"Nao", "Hanazonkk", "Zynch", "ChikenCip", "Zaro", "Nanno", "Ftx", "Kokee"};

int jelajahalamsek(int n, int d){
    if(d > 0){
        printf("%s menemukan %d jumlah diamond di cave ke-%d\n", member[n % 8], d, n+1);
        return d;
    }
    return 0;
}
int main(){
    int N, d;
    scanf("%d", &N);
    int total = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &d);
        total += jelajahalamsek(i, d);////ini intinya nanti harus diprint sek selama d > 0 trs
    }

    if(total > 0){
        printf("\nDIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
        printf("Total jumlah diamond yang didapat: %d\n", total);
        if(total <= 64){
            printf("Ftx sama Zynch wajib traktir GOONERS lain");
        }else if(total <= 128){
            printf("GOONERS tidur besok nguli lagi");
        }else{
            printf("Para GOONERS makan-makan hari ini");
        }
    }else{
        printf("That's La Peace\n");
        printf("Sayang sekali Tim GOONERS pulang dengan tangan kosong");
    }
    return 0;
}