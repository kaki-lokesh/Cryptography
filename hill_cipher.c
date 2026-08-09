#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isValid(char text[]) {
    for(int i=0; text[i]!='\0'; i++) {
        if(!isalpha((unsigned char)text[i]))
            return 0;
    }
    return 1;
}

int main()
{
    int key[2][2];
    char text[100];
    printf("Enter 2x2 Key Matrix: \n");
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            scanf("%d", &key[i][j]);
    printf("Enter Plain Text: ");
    getchar();
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    if(!isValid(text)) {
        printf("Invalid Input");
        return 0;
    }
    for(int i=0; text[i]; i++)
        text[i] = toupper((unsigned char)text[i]);
    int len = strlen(text);
    if(len%2 != 0) {
        text[len] = 'X';
        text[len+1] = '\0';
        len++;
    }
    printf("Cipher Text: ");
    for(int i=0; i<len; i+=2) {
        int a = text[i]-'A';
        int b = text[i+1]-'A';
        int c1 = (key[0][0]*a + key[0][1]*b)%26;
        int c2 = (key[1][0]*a + key[1][1]*b)%26;
        printf("%c%c", c1+'A', c2+'A');
    }
    return 0;
}



