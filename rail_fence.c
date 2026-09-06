#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValid(char s[]) {
    for(int i=0; s[i]; i++)
        if(!isalpha((unsigned char)s[i]) && s[i]!=' ')
            return 0;
    return 1;
}

int main() {
    char text[100], enc[100], dec[100];
    int rails, i, r, row, k=0, len;
    printf("Enter text: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter number of rails: ");
    scanf("%d", &rails);
    if(!isValid(text) || rails < 2) {
        printf("Invalid Input");
        return 0;
    }
    for(i=0; text[i]; i++)
        text[i] = toupper((unsigned char)text[i]);
    len = strlen(text);

    // Encryption
    for(r=0; r<rails; r++) {
        for(i=0; i<len; i++) {
            row = i % (2*rails-2);
            if(row >= rails)
                row = 2*rails-2-row;
            if(row == r)
                enc[k++] = text[i];
        }
    }
    enc[k] = '\0';
    printf("Cipher Text: %s\n", enc);

    // Decryption
    k = 0;
    for(r=0; r<rails; r++) {
        for(i=0; i<len; i++) {
            row = i % (2*rails-2);
            if(row >= rails)
                row = 2*rails-2-row;
            if(row == r)
                dec[i] = enc[k++];
        }
    }
    dec[len] = '\0';
    printf("Decrypted Text: %s\n", dec);
    return 0;
}