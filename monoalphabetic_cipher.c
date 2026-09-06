#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[26];
    int i;
    printf("Enter text: ");
    fgets(text, 100, stdin);
    printf("Enter key: ");
    fgets(key, 26, stdin);

    // Encryption
    printf("Encrypted: ");
    for(i = 0; text[i]; i++) {
        if(isalpha(text[i])) {
            char c = toupper(text[i]);
            putchar(key[c - 'A']);
        } else putchar(text[i]);
    }

    // Decryption
    printf("\nDecrypted: ");  
    for(i = 0; text[i]; i++) {
        if(isalpha(text[i])) {
            char c = toupper(text[i]);
            for(int j = 0; j < 26; j++)
                if(key[j] == c) putchar('A' + j);
        } else putchar(text[i]);
    }
    return 0;
}