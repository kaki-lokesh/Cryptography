#include <stdio.h>

int main() {
    int a[2][2];
    int inv[2][2], det, i;
    char text[100], enc[100], dec[100];
    int x, y;
    printf("Enter even-length text: ");
    scanf("%s", text);
    printf("Enter 2x2 Key Matrix: \n");
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            scanf("%d", &a[i][j]);

    // Encryption
    for(i = 0; text[i]; i += 2) {
        x = text[i] - 'A';
        y = text[i+1] - 'A';
        enc[i]   = (a[0][0]*x + a[0][1]*y) % 26 + 'A';
        enc[i+1] = (a[1][0]*x + a[1][1]*y) % 26 + 'A';
    }
    enc[i] = '\0';

    // Inverse matrix
    det = (a[0][0]*a[1][1] - a[0][1]*a[1][0] + 26) % 26;
    for(i = 1; i < 26; i++)
        if(det * i % 26 == 1) break;
    inv[0][0] = a[1][1] * i % 26;
    inv[0][1] = -a[0][1] * i % 26;
    inv[1][0] = -a[1][0] * i % 26;
    inv[1][1] = a[0][0] * i % 26;
    
    // Decryption
    for(i = 0; enc[i]; i += 2) {
        x = enc[i] - 'A';
        y = enc[i+1] - 'A';
        dec[i]   = (inv[0][0]*x + inv[0][1]*y + 26) % 26 + 'A';
        dec[i+1] = (inv[1][0]*x + inv[1][1]*y + 26) % 26 + 'A';
    }
    dec[i] = '\0';
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}


