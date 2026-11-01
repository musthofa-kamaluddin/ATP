#include <stdio.h>

int target = 1;
// int diamond(int arr[], int n, int idx){
    
//     if(idx == n){
//         printf("That's La Peace");
//         return 0;
//     }
    
//     if(arr[idx] == target){
//         printf("DIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
//         printf("Diamond ditemukan pada cave ke-%d", idx+1);
//         return 0;
//     }

//     return diamond(arr, n, idx+1);
// }

int main(){
    int n;
    int adaDiamond = 0;
    int posisi = 0;
    scanf("%d", &n);

    int d[n]; 
    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
        if (d[i] == 1){
            adaDiamond = 1;
            posisi = i+1;
        }    
    }

    if(adaDiamond){
        printf("DIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
        printf("Diamond ditemukan pada cave ke-%d", posisi);
    }else{
        printf("That's La Peace");
    }
    
    // diamond(d, n, 0);
    return 0;
}