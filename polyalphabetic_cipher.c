#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValid(char s[]) {
    for(int i=0; s[i]; i++)
        if(!isalpha((unsigned char)s[i]))
            return 0;
    return 1;
}

int main() {
    char text[100], key[100], enc[100], dec[100];
    int i, k;
    printf("Enter text: ");
    scanf("%99s", text);
    printf("Enter key: ");
    scanf("%99s", key);
    if(!isValid(text) || !isValid(key)) {
        printf("Invalid Input");
        return 0;
    }
    for(i=0; text[i]; i++)
        text[i] = toupper((unsigned char)text[i]);
    for(i=0; key[i]; i++)
        key[i] = toupper((unsigned char)key[i]);
    k = strlen(key);

    // Encryption & Decryption
    for(i=0; text[i]; i++) {
        enc[i] = (text[i]-'A' + key[i%k]-'A')%26 + 'A';
        dec[i] = (enc[i]-'A' - key[i%k]+'A'+26)%26 + 'A';
    }
    enc[i] = dec[i] = '\0';
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}