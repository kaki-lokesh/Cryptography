#include <stdio.h>
#include <string.h>

void trans(char in[], char out[], char key[]) {
    int n=strlen(key), len=strlen(in);
    int i,j,k=0, order[20];
    for(i=0;i<n;i++) order[i]=i;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(key[order[i]] > key[order[j]]) {
                int t=order[i];
                order[i]=order[j];
                order[j]=t;
            }
    for(i=0;i<n;i++)
        for(j=order[i];j<len;j+=n)
            out[k++]=in[j];
    out[k]='\0';
}

void detrans(char in[], char out[], char key[]) {
    int n=strlen(key), len=strlen(in);
    int rows=(len+n-1)/n, i,j,k=0, order[20];
    for(i=0;i<n;i++) order[i]=i;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(key[order[i]] > key[order[j]]) {
                int t=order[i];
                order[i]=order[j];
                order[j]=t;
            }
    for(i=0;i<n;i++)
        for(j=order[i];j<len;j+=n)
            out[j]=in[k++];
    out[len]='\0';
}

int main() {
    char text[100], a[100], enc[100], dec[100];
    char key[20];
    printf("Enter text: ");
    scanf("%s",text);
    printf("Enter key: ");
    scanf("%s",key);
    trans(text,a,key);
    trans(a,enc,key);
    printf("Encrypted: %s\n",enc);
    detrans(enc,a,key);
    detrans(a,dec,key);
    printf("Decrypted: %s\n",dec);
    return 0;
}