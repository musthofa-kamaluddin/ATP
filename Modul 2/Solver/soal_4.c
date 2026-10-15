#include <stdio.h>
#include <string.h>

int main(){
    int N, M;
    int b = 0, k = 0, len = 0;

    scanf("%d %d", &N, &M);

    //para array mahadahsyat yang qnantikan
    char peta[100][101];// kolom tak kasih +1 buat space null terminator \0, in case beneran kepakek 100x100
    int alrVisited[100][100];
    char ans[10000];

    for(int i = 0; i < N; i++){
        scanf("%s", peta[i]);
        for(int j = 0; j < M; j++){
            alrVisited[i][j] = 0;
        }
    }
    //krn 0,0 pasti 1 jadi
    alrVisited[0][0] = 1;

    while(peta[b][k] != 'E'){
        // kanan,bawah, kiri, atas
        if(k + 1 < M && peta[b][k+1] != '#' && alrVisited[b][k+1] == 0){
            k++;
            alrVisited[b][k] = 1;
            ans[len++] = 'R';
        }else if(b + 1 < N && peta[b+1][k] != '#' && alrVisited[b+1][k] == 0){
            b++;
            alrVisited[b][k] = 1;
            ans[len++] = 'D';
        }else if(k - 1 >= 0 && peta[b][k-1] != '#' && alrVisited[b][k-1] == 0){
            k--;
            alrVisited[b][k] = 1;
            ans[len++] = 'L';
        }else if(b - 1 >= 0 && peta[b-1][k] != '#' && alrVisited[b-1][k] == 0){
            b--;
            alrVisited[b][k] = 1;
            ans[len++] = 'U';
        }else{ //klw buntu smw
            if(len == 0){
                printf("Ditolak loh yaa awokawok");
                return 0;
            }
            len--;
            if(ans[len] == 'R'){
                k--;//balek kiri
            }else if(ans[len] == 'D'){
                b--;//balek atas
            }else if(ans[len] == 'L'){
                k++;//balek kanan
            }else if(ans[len] == 'U'){
                b++;//balek bawah
            }
        }
    }

    ans[len] = '\0';//kasih stop di arr ans nya setelah kondisi while soalnya gaada end nya
    printf("%s", ans);
    //nyanyi sek
    printf("\nYang datang dan pergi\nKan membuatmu mengerti\nKarna kita terlalu tersakiti\nTuk mengenal perih\nYang dan dan pergi\nSemua yang harus di lalui\nKarna kita terlalu tersakiti\nTuk menjadi manusia\n");
    return 0;
}