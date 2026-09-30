#include <stdio.h>

int main() {
    int SA, EA, SB, EB, SAH, SAM, EAH, EAM, SBH, SBM, EBH, EBM;
    scanf("%d:%d %d:%d", &SAH, &SAM, &EAH, &EAM);
    scanf("%d:%d %d:%d", &SBH, &SBM, &EBH, &EBM);

    SA = (SAH * 60) + SAM;
    EA = (EAH * 60) + EAM;
    SB = (SBH * 60) + SBM;
    EB = (EBH * 60) + EBM;

    if(EA <= SA){
        EA = EA + 1440;
    }
    if(EB <= SB){
        EB = EB + 1440;
    }

    int overlap = 0;
    int awal, akhir;

    awal = SA;
    if(SB - 1440 > awal){
        awal = SB - 1440;
    }
    akhir = EA;
    if(EB - 1440 < akhir){
        akhir = EB - 1440;
    }
    if(akhir > awal){
        overlap = overlap + (akhir - awal);
    }

    awal = SA;
    if(SB > awal){
        awal = SB;
    }
    akhir = EA;
    if(EB < akhir){
        akhir = EB;
    }
    if(akhir > awal){
        overlap = overlap + (akhir - awal);
    }

    awal = SA;
    if(SB + 1440 > awal){
        awal = SB + 1440;
    }
    akhir = EA;
    if(EB + 1440 < akhir){
        akhir = EB + 1440;
    }
    if(akhir > awal){
        overlap = overlap + (akhir - awal);
    }

    printf("%d ", overlap);
    if(overlap > 180){
        printf("WALL SECURE");
    }else if(overlap >= 60 && overlap <= 180){
        printf("ALERT");
    }else if(overlap >= 1 && overlap < 60){
        printf("HIGH ALERT");
    }else if(overlap == 0){
        printf("TITAN BREACH");
    }
    return 0;
}