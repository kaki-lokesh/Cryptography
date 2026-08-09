#include<stdio.h>
#include<string.h>
#include<ctype.h>

char matrix[5][5];

int isValid(char text[]) {
    for(int i=0; text[i]; i++) {
        if(!isalpha(text[i]))
            return 0;
    }
    return 1;
}

void generateMatrix(char key[]) {
    int used[26] = {0};
    used['J'-'A'] = 1;
    char temp[25];
    int k = 0;
    for(int i=0; key[i]; i++) {
        char ch = toupper(key[i]);
        if(ch == 'J')
            ch = 'I';
        if(!used[ch-'A']) {
            used[ch-'A'] = 1;
            temp[k++] = ch;
        }
    }
    for(char ch='A'; ch<='Z'; ch++) {
        if(!used[ch-'A']) {
            used[ch-'A'] = 1;
            temp[k++] = ch;
        }
    }
    k = 0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            matrix[i][j] = temp[k++];
}

void findPos(char ch,int *r,int *c) {
    if(ch == 'J')
        ch = 'I';
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(matrix[i][j] == ch) {
                *r = i;
                *c = j;
                return;
            }
}

int main() {
    char key[50], text[100];
    printf("Enter Key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter Plain Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    if(!isValid(key) || !isValid(text)) {
        printf("Invalid Input");
        return 0;
    }
    for(int i=0; key[i]; i++)
        key[i] = toupper(key[i]);
    for(int i=0; text[i]; i++)
        text[i] = toupper(text[i]);
    generateMatrix(key);
    char plain[200];
    int j = 0;
    int len = strlen(text);
    for(int i = 0; i < len; ) {
        char first = (text[i] == 'J') ? 'I' : text[i];
        if(i+1 >= len) {
            plain[j++] = first;
            plain[j++] = 'X';
            i++;
        } else {
            char second = (text[i+1] == 'J') ? 'I' : text[i+1];
            plain[j++] = first;
            if(first == second) {
                plain[j++] = 'X';
                i++;
            } else {
                plain[j++] = second;
                i += 2;
            }
        }
    }
    plain[j] = '\0';
    printf("Cipher Text: ");
    for(int i=0; i<j; i+=2) {
        int r1, c1, r2, c2;
        findPos(plain[i], &r1, &c1);
        findPos(plain[i+1], &r2, &c2);
        if(r1 == r2) {
            printf("%c%c", matrix[r1][(c1+1)%5], matrix[r2][(c2+1)%5]);
        } else if(c1 == c2) {
            printf("%c%c", matrix[(r1+1)%5][c1], matrix[(r2+1)%5][c2]);
        } else {
            printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }
    }
    return 0;
}