#include <stdio.h>

int cariNamek(int A[], int N, int S) {
    int dist[100];
    int queue[100];
    int head = 0, tail = 0;
    for (int i = 0; i < N; i++) dist[i] = -1;
    dist[S] = 0;
    queue[tail++] = S;
    while (head < tail) {
        int cur = queue[head++];
        if (A[cur] == 0) {
            return dist[cur];
        }
        int kanan = cur + A[cur];
        int kiri  = cur - A[cur];
        if (kanan < N && dist[kanan] == -1) {
            dist[kanan] = dist[cur] + 1;
            queue[tail++] = kanan;
        }
        if (kiri >= 0 && dist[kiri] == -1) {
            dist[kiri] = dist[cur] + 1;
            queue[tail++] = kiri;
        }
    }
    return -1;
}

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    int A[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int L = cariNamek(A, N, S);
    if (L == -1) {
        printf("-1");
    } else {
        printf("%d %d %d", L, L * 3, L + 7);
    }
    return 0;
}