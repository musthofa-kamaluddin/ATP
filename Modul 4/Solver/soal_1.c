#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++){
        int n;
        scanf("%d", &n);

        int total = 0, max = 0, min = 0;
        for(int j = 0; j < n; j++){
            int a;
            scanf("%d", &a);
            total += a;
            if(j == 0 || a > max) max = a; 
            if(j == 0 || a < min) min = a; 
        }

        printf("---Siklus %d---\n", i);
        printf("Total: %d\n", total);
        printf("Rata-rata: %.2f\n", (double)total/n);
        printf("Tertinggi: %d\n", max);
        printf("Terendah: %d\n", min);
    }
    return 0;
}