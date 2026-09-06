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
    int k[2][2], inv[2][2], det, idet;
    int i, x, y, len;
    char text[100], enc[100], dec[100];
    printf("Enter 2x2 Key Matrix:\n");
    for(i=0;i<2;i++)
        scanf("%d%d",&k[i][0],&k[i][1]); 
    printf("Enter Plain Text: ");
    scanf("%99s",text);
    if(!isValid(text)) {
        printf("Invalid Input");
        return 0;
    }
    for(i=0;text[i];i++)
        text[i]=toupper((unsigned char)text[i]);
    len=strlen(text);
    if(len%2) {
        text[len]='X';
        text[len+1]='\0';
        len++;
    }
    det=(k[0][0]*k[1][1]-k[0][1]*k[1][0])%26;
    if(det<0) det+=26;
    for(idet=1;idet<26;idet++)
        if(det*idet%26==1)
            break;
    if(idet==26) {
        printf("Invalid Key Matrix");
        return 0;
    }

    // Encryption
    for(i=0;i<len;i+=2) {
        x=text[i]-'A';
        y=text[i+1]-'A';
        enc[i]=(k[0][0]*x+k[0][1]*y)%26+'A';
        enc[i+1]=(k[1][0]*x+k[1][1]*y)%26+'A';
    }
    enc[len]='\0';

    // Inverse Matrix
    inv[0][0]= k[1][1]*idet%26;
    inv[0][1]=(-k[0][1]*idet%26+26)%26;
    inv[1][0]=(-k[1][0]*idet%26+26)%26;
    inv[1][1]= k[0][0]*idet%26;

    // Decryption
    for(i=0;i<len;i+=2) {
        x=enc[i]-'A';
        y=enc[i+1]-'A';
        dec[i]=(inv[0][0]*x+inv[0][1]*y)%26+'A';
        dec[i+1]=(inv[1][0]*x+inv[1][1]*y)%26+'A';
    }
    dec[len]='\0';
    printf("Cipher Text: %s\n",enc);
    printf("Decrypted Text: %s\n",dec);
    return 0;
}