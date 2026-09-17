#include <stdio.h>

int main() {
    int N, K;

    scanf("%d", &N);
    scanf("%d", &K);

    (N % 3 == 0 && K % 3 == 0) ? printf("Doa ayang berhasil!") : printf("Skill issue banget wok");
}