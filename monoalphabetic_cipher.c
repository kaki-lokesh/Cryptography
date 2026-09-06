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
    char text[100], key[27], enc[100], dec[100];
    int i, j, used[26] = {0};
    printf("Enter text: ");
    scanf("%99s", text);
    printf("Enter key: ");
    scanf("%26s", key);
    if(!isValid(text) || strlen(key) != 26 || !isValid(key)) {
        printf("Invalid Input");
        return 0;
    }
    for(i=0; i<26; i++) {
        key[i] = toupper((unsigned char)key[i]);
        if(used[key[i]-'A']) {
            printf("Invalid Input");
            return 0;
        }
        used[key[i]-'A'] = 1;
    }

    // Encryption
    for(i=0; text[i]; i++) {
        text[i] = toupper((unsigned char)text[i]);
        enc[i] = key[text[i]-'A'];
    }
    enc[i] = '\0';

    // Decryption
    for(i=0; enc[i]; i++)
        for(j=0; j<26; j++)
            if(key[j] == enc[i])
                dec[i] = 'A' + j;
    dec[i] = '\0';
    printf("Encrypted: %s\n", enc);
    printf("Decrypted: %s\n", dec);
    return 0;
}