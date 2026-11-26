#include <stdio.h>

int n, m;
long long A[100005], B[100005], T[100005];

// merge sort untuk B
void msort(int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;
    msort(l, mid);
    msort(mid, r);
    int i = l, j = mid, k = l;
    while (i < mid && j < r) {
        if (B[i] <= B[j]) T[k++] = B[i++];
        else T[k++] = B[j++];
    }
    while (i < mid) T[k++] = B[i++];
    while (j < r) T[k++] = B[j++];
    for (k = l; k < r; k++) B[k] = T[k];
}

// banyak elemen B yang nilainya <= x
int count_le(long long x) {
    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (B[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// banyak pasangan dengan |a - b| <= X
long long f(long long X) {
    if (X < 0) return 0;
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += count_le(A[i] + X) - count_le(A[i] - X - 1);
    }
    return total;
}

int main() {
    long long L, R;
    scanf("%d %d %lld %lld", &n, &m, &L, &R);
    for (int i = 0; i < n; i++) scanf("%lld", &A[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &B[i]);

    msort(0, m);

    long long ans = f(2 * R) - f(2 * L - 1);
    printf("%lld\n", ans);
    return 0;
}