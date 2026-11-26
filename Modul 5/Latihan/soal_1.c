#include <stdio.h>

int p[100000];

int lowerBound(int n, int x) {
    int low = 0,high = n;
    while (low < high) {
        int mid = low + (high-low) / 2;
        if (p[mid] >= x) high = mid;
        else low = mid + 1;
    }
    return low;
}

int upperBound(int n, int x) {
    int low = 0,high = n;
    while (low < high) {
        int mid = low + (high-low) / 2;
        if (p[mid] > x) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    int n, q, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
        

    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", upperBound(n, r) - lowerBound(n, l));
    }
    return 0;
}