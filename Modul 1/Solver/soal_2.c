#include <stdio.h>

int main() {
    int A, B, C, R, D, MAX, MIN;
    scanf("%d %d %d", &A, &B, &C);
    R = (A + B + C) / 3;

    if(A > B){
        if(A > C){
            MAX = A;
            if(B > C){
                MIN = C;
            }else{
                MIN = B;
            }
        }else{
            MAX = C;
            MIN = B;
        }
    }else{
        if(B > C){
            MAX = B;
            if(A > C){
                MIN = C;
            }else{
                MIN = A;
            }
        }else{
            MAX = C;
            MIN = A;
        }
    }
    
    D = MAX - MIN;

    if(A == 0 || B == 0 || C == 0){
        printf("SHUTDOWN");
        return 0;
    }

    if(R >= 80 && D <= 10){
        printf("STABLE %d %d", R, D);
    }else if(R >= 80 && D > 10){
        printf("OVERLOAD %d %d", R, D);
    }else if(R >= 60 || (R >= 50 && D <= 5)){
        printf("WARNING %d %d", R, D);
    }else{
        printf("CRITICAL %d %d", R, D);
    }
    return 0;
}