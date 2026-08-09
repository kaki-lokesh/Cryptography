#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isValid(char text[]) {
    for(int i=0; text[i]; i++) {
        if(!isalpha(text[i]))
            return 0;
    }
    return 1;
}

int main() {
    char text[100],key[100];
    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter Key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    if(!isValid(text) || !isValid(key)) {
        printf("Invalid Input");
        return 0;
    }
    for(int i=0; text[i]; i++)
        text[i] = toupper(text[i]);
    for(int i=0; key[i]; i++)
        key[i] = toupper(key[i]);
    int len = strlen(text);
    int keyLen = strlen(key);
    printf("Cipher Text: ");
    for(int i=0; i<len; i++) {
        char c = ((text[i]-'A') + (key[i%keyLen]-'A'))%26 + 'A';
        printf("%c", c);
    }
    return 0;
}