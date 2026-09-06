#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValid(char s[]) {
    for(int i=0; s[i]; i++)
        if(!isalpha((unsigned char)s[i]) && s[i]!=' ')
            return 0;
    return 1;
}

void order(char key[], int o[]) {
    int i,j,t,n=strlen(key);
    for(i=0;i<n;i++)
        o[i]=i;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(key[o[i]] > key[o[j]]) {
                t=o[i];
                o[i]=o[j];
                o[j]=t;
            }
}

void trans(char in[], char out[], char key[]) {
    int n=strlen(key), len=strlen(in);
    int o[20], i,j,k=0;
    order(key,o);
    for(i=0;i<n;i++)
        for(j=o[i];j<len;j+=n)
            out[k++]=in[j];
    out[k]='\0';
}

void detrans(char in[], char out[], char key[]) {
    int n=strlen(key), len=strlen(in);
    int o[20], i,j,k=0;
    order(key,o);
    for(i=0;i<n;i++)
        for(j=o[i];j<len;j+=n)
            out[j]=in[k++];
    out[len]='\0';
}

int main() {
    char text[100], a[100], enc[100], dec[100], key[20];
    int i;
    printf("Enter text: ");
    fgets(text,100,stdin);
    text[strcspn(text,"\n")]='\0';
    printf("Enter key: ");
    scanf("%19s",key);
    if(!isValid(text) || !isValid(key)) {
        printf("Invalid Input");
        return 0;
    }
    for(i=0;text[i];i++) {
        if(text[i]==' ')
            text[i]='X';
        else
            text[i]=toupper((unsigned char)text[i]);
    }
    for(i=0;key[i];i++)
        key[i]=toupper((unsigned char)key[i]);
    // Encryption
    trans(text,a,key);
    trans(a,enc,key);
    printf("Cipher Text: %s\n",enc);
    // Decryption
    detrans(enc,a,key);
    detrans(a,dec,key);
    printf("Decrypted Text: %s\n",dec);
    return 0;
}