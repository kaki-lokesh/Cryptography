#include <stdio.h>

int main() {
    char text[100], enc[100], dec[100];
    int key, i;
    printf("Enter text: ");
    fgets(text, 100, stdin);
    printf("Enter key: ");
    scanf("%d", &key);

    // Encryption
    for(i = 0; text[i]; i++) {  
        if(text[i] >= 'A' && text[i] <= 'Z')
            enc[i] = (text[i] - 'A' + key) % 26 + 'A';
        else
            enc[i] = text[i];
    }
    enc[i] = '\0';

    // Decryption
    for(i = 0; enc[i]; i++) {
        if(enc[i] >= 'A' && enc[i] <= 'Z')
            dec[i] = (enc[i] - 'A' - key + 26) % 26 + 'A';
        else
            dec[i] = enc[i];
    }
    dec[i] = '\0';
    printf("Encrypted: %s", enc);
    printf("Decrypted: %s", dec);
    return 0;
}