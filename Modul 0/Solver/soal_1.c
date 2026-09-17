#include <stdio.h>

int main() {
    float x1, x2, y1, y2;
    double gradien;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);
    
    (x1 == x2) ? (gradien = 0) : (gradien = (y2 - y1) / (x2 - x1));
    (x1 == x2) ? printf("Gradien garis: tidak terdefinisi") : printf("Gradien garis: %.2lf", gradien);

    return 0;
}