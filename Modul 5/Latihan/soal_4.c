#include <stdio.h>

int nrp[10005];
int jumlah_partisi = 0;

void quick_sort(int kiri, int kanan) {
    if (kiri >= kanan) return;

    jumlah_partisi++;

    int pivot = nrp[kiri];
    int batas = kiri + 1; 

    for (int i = kiri + 1; i <= kanan; i++) {
        if (nrp[i] < pivot) {
            int tmp = nrp[i];
            nrp[i] = nrp[batas];
            nrp[batas] = tmp;
            batas++;
        }
    }

    int posisi_pivot = batas - 1;
    int tmp = nrp[kiri];
    nrp[kiri] = nrp[posisi_pivot];
    nrp[posisi_pivot] = tmp;

    quick_sort(kiri, posisi_pivot - 1);
    quick_sort(posisi_pivot + 1, kanan);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nrp[i]);
    }

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", nrp[i]);
    }
    printf("\n%d\n", jumlah_partisi);

    return 0;
}