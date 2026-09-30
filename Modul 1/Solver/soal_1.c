#include <stdio.h>

int main() {
    int method;
    int hargaAwal, biayaAdmin, total;

    scanf("%d", &method);
    scanf("%d", &hargaAwal);

    if(method > 0 && method < 5){
    printf("========STRUK PEMBELIAN========\n");
    printf("Harga: Rp%d\n", hargaAwal);
    printf("Metode Pembayaran: ");
    switch(method){
        case 1:
            biayaAdmin = 0;
            printf("Tunai\n");
            break;
        case 2:
            biayaAdmin = 1000;
            printf("QRIS\n");
            break;
        case 3:
            biayaAdmin = 1500;
            printf("FastPayment\n");
            break;
        case 4:
            biayaAdmin = 6000;
            printf("Transfer Bank\n");
            break;
        default:
            printf("SISTEM TIDAK DIKENALI!\n");
    }
    printf("Biaya Admin: Rp%d\n", biayaAdmin);
    total = hargaAwal + biayaAdmin;
    printf("-------------------------------\n");
    printf("Total Biaya: Rp%d", total);
    }else{
        printf("SISTEM TIDAK DIKENALI!\n");
        return 0;
    }
return 0;
}