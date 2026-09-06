#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

int isValid(char s[]) {
    for(int i=0;s[i];i++)
        if(!isalpha((unsigned char)s[i]))
            return 0;
    return 1;
}

void create(char key[]) {
    int used[26]={0},r=0,c=0,i;
    char ch;
    used['J'-'A']=1;
    for(i=0;key[i];i++) {
        ch=toupper((unsigned char)key[i]);
        if(ch=='J') ch='I';
        if(!used[ch-'A']) {
            mat[r][c++]=ch;
            used[ch-'A']=1;
            if(c==5) c=0,r++;
        }
    }
    for(ch='A';ch<='Z';ch++)
        if(!used[ch-'A']) {
            mat[r][c++]=ch;
            used[ch-'A']=1;
            if(c==5) c=0,r++;
        }
}

void find(char ch,int *r,int *c) {
    int i,j;
    if(ch=='J') ch='I';
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(mat[i][j]==ch) {
                *r=i;
                *c=j;
                return;
            }
}

void process(char text[],int decrypt) {
    int i,r1,c1,r2,c2,t;
    for(i=0;text[i];i+=2) {
        find(text[i],&r1,&c1);
        find(text[i+1],&r2,&c2);
        if(r1==r2) {
            c1=(c1+(decrypt?4:1))%5;
            c2=(c2+(decrypt?4:1))%5;
        } else if(c1==c2) {
            r1=(r1+(decrypt?4:1))%5;
            r2=(r2+(decrypt?4:1))%5;
        } else {
            t=c1;
            c1=c2;
            c2=t;
        }
        text[i]=mat[r1][c1];
        text[i+1]=mat[r2][c2];
    }
}

int main() {
    char key[100],text[100],p[200],enc[200];
    int i,k=0;
    printf("Enter key: ");
    scanf("%99s",key);
    printf("Enter text: ");
    scanf("%99s",text);
    if(!isValid(key) || !isValid(text)) {
        printf("Invalid Input");
        return 0;
    }
    create(key);    
    for(i=0;text[i];) {
        p[k++]=toupper((unsigned char)text[i]);
        if(p[k-1]=='J') p[k-1]='I';
        if(!text[i+1]) {
            p[k++]='X';
            i++;
        } else if(p[k-1]==toupper((unsigned char)text[i+1]) ||
                p[k-1]=='I' && toupper((unsigned char)text[i+1])=='J') {
            p[k++]='X';
            i++;
        } else {
            p[k++]=toupper((unsigned char)text[i+1]);
            if(p[k-1]=='J') p[k-1]='I';
            i+=2;
        }
    }
    p[k]='\0';
    strcpy(enc,p);
    process(enc,0);
    printf("Cipher Text: %s\n",enc);
    process(enc,1);
    printf("Decrypted Text: %s\n",enc);
    return 0;
}