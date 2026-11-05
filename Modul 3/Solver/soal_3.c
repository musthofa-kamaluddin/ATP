#include <stdio.h>

int N, S;
int A[100];
int dikunjungi[100];
int y;
int caribolanagacoyyyy(int pos, int step){
    int next;
    if(A[pos] == 0){y = pos; return step;}
    dikunjungi[pos] = 1;

    if(A[pos] % 2 == 0) next = pos + A[pos];
    else next = pos - A[pos];

    if(next < 0 || next >= N || dikunjungi[next]) return -1;
    return caribolanagacoyyyy(next, step + 1);
}
int main(){
    scanf("%d %d", &N, &S);

    int total = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        dikunjungi[i] = 0;
    }
    int z = caribolanagacoyyyy(S, 0);
    if( z == -1) printf("-1");
    else printf("%d %d %d", S, y, z);
    return 0;
}