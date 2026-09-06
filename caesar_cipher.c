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
    char text[100], enc[100], dec[100];
    int key, i;
    printf("Enter text: ");
    scanf("%99s", text);
    if(!isValid(text)) {
        printf("Invalid Input");
        return 0;
    }
    printf("Enter key: ");
    scanf("%d", &key);
    key = (key % 26 + 26) % 26;
    
    // Encryption & Decryption
    for(i=0; text[i]; i++) {
        text[i] = toupper((unsigned char)text[i]);
        enc[i] = (text[i]-'A'+key)%26 + 'A';
        dec[i] = (enc[i]-'A'-key+26)%26 + 'A';
    }
    enc[i] = dec[i] = '\0';
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}