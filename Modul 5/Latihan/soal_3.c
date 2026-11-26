#include <stdio.h>

long long B[100005];
long long jumlah[100005];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    jumlah[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &B[i]);
        jumlah[i + 1] = jumlah[i] + B[i];
    }

    for (int j = 0; j < q; j++) {
        long long p;
        int k;
        scanf("%lld %d", &p, &k);

        int kiri = 0;
        int kanan = n;
        while (kiri < kanan) {
            int tengah = (kiri + kanan) / 2;
            if (B[tengah] <= p) {
                kiri = tengah + 1;
            } else {
                kanan = tengah;
            }
        }
        int bisa = kiri;

        int ambil = bisa;
        if (k < ambil) ambil = k;
        long long total = jumlah[bisa] - jumlah[bisa - ambil];
        printf("%d %lld\n", ambil, total);
    }

    return 0;
}