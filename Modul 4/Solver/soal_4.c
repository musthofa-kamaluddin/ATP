#include <stdio.h>
#include <string.h>

struct Misi {
    char siswa[31];
    char roh[31];
    int grade;
    long long energi;
    int dihapus;
};

struct Misi hehe[2005];

void revisi(struct Misi *log, long long energi){
    (*log).energi = energi;
}

void tukar(struct Misi *a, struct Misi *b){
    char tmp[31];
    strcpy(tmp, (*a).siswa);
    strcpy((*a).siswa, (*b).siswa);
    strcpy((*b).siswa, tmp);
}

void hapus(struct Misi *log){
    (*log).dihapus = 1;
}

int main(){
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %s %d %lld", hehe[i].siswa, hehe[i].roh, &hehe[i].grade, &hehe[i].energi);
        hehe[i].dihapus = 0;
    }

    scanf("%d", &M);
    while(M--){
        char perintah[10];
        scanf("%s", perintah);

        if(strcmp(perintah, "MISI") == 0){
            scanf("%s %s %d %lld", hehe[N].siswa, hehe[N].roh, &hehe[N].grade, &hehe[N].energi);
            hehe[N].dihapus = 0;
            N++;
        }else if(strcmp(perintah, "REVISI") == 0){
            int y;
            long long e;
            scanf("%d %lld", &y, &e);
            revisi(&hehe[y-1], e);
        }else if(strcmp(perintah, "HAPUS") == 0){
            int y;
            scanf("%d", &y);
            hapus(&hehe[y-1]);
        }else if(strcmp(perintah, "TUKAR") == 0){
            int a, b;
            scanf("%d %d", &a, &b);
            tukar(&hehe[a-1], &hehe[b-1]);
        }else if(strcmp(perintah, "LAPOR") == 0){
            char cari[31];
            scanf("%s", cari);
            printf("%s\n", cari);

            int count = 0, scount = 0, best = -1;
            long long sum = 0;

            for (int i = 0; i < N; i++){
                if(hehe[i].dihapus) continue;
                if(strcmp(hehe[i].siswa, cari) != 0) continue;
                count++;
                sum += hehe[i].energi;
                if(hehe[i].grade == 0) scount++;
                if(best == -1 || hehe[i].energi > hehe[best].energi) best = i;
            }

            if(count == 0){
                printf("TIDAK ADA MISI\n");
                continue;
            }

            char *badge;
            if(sum >= 500000) badge = "SPECIAL GRADE SISWA";
            else if(sum >= 100000) badge = "GRADE 1 SISWA";
            else if(sum >= 10000) badge = "GRADE 2 SISWA";
            else badge = "GRADE 3 SISWA";

            printf("Jumlah misi: %d\n", count);
            printf("Total energi terkutuk: %lld\n", sum);
            printf("Roh terkuat: %s (%lld)\n", hehe[best].roh, hehe[best].energi);
            printf("Special grade dikalahkan: %d\n", scount);
            printf("Kategori: %s\n", badge);
            }
        }
    return 0;
}