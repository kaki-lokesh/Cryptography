#include <stdio.h>
#include <string.h>

int main() {
    char text[100], key[100], enc[100], dec[100];
    int i, j = 0, k;
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter key: ");
    scanf("%s", key);
    k = strlen(key);

    // Encryption
    for(i = 0; text[i]; i++) {
        enc[i] = (text[i] - 'A' + key[j] - 'A') % 26 + 'A';
        j = (j + 1) % k;
    }
    enc[i] = '\0';
    
    // Decryption
    j = 0;
    for(i = 0; enc[i]; i++) {
        dec[i] = (enc[i] - 'A' - (key[j] - 'A') + 26) % 26 + 'A';
        j = (j + 1) % k;
    }
    dec[i] = '\0';
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}