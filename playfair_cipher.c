#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void create(char key[]) {
    int used[26] = {0}, r = 0, c = 0, i;
    char ch;
    used['J'-'A'] = 1;
    for(i = 0; key[i]; i++) {
        ch = toupper(key[i]);
        if(ch == 'J') ch = 'I';
        if(ch >= 'A' && ch <= 'Z' && !used[ch-'A']) {
            mat[r][c++] = ch;
            used[ch-'A'] = 1;
            if(c == 5) c=0, r++;
        }
    }
    for(ch='A'; ch<='Z'; ch++) {
        if(!used[ch-'A']) {
            mat[r][c++] = ch;
            used[ch-'A'] = 1;
            if(c == 5) c=0, r++;
        }
    }
}

void find(char ch, int *r, int *c) {
    int i,j;
    if(ch == 'J') ch = 'I';
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(mat[i][j] == ch)
                *r=i, *c=j;
}

void process(char text[], int decrypt) {
    int i, r1,c1,r2,c2;
    char a,b;
    for(i=0;text[i];i+=2) {
        a=text[i];
        b=text[i+1];
        find(a,&r1,&c1);
        find(b,&r2,&c2);
        if(r1 == r2) {
            c1 = (c1 + (decrypt ? 4 : 1)) % 5;
            c2 = (c2 + (decrypt ? 4 : 1)) % 5;
        } else if(c1 == c2) {
            r1 = (r1 + (decrypt ? 4 : 1)) % 5;
            r2 = (r2 + (decrypt ? 4 : 1)) % 5;
        } else {
            int t=c1;
            c1=c2;
            c2=t;
        }
        text[i]=mat[r1][c1];
        text[i+1]=mat[r2][c2];
    }
}

int main() {
    char key[50], text[100], enc[100];
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter even-length text: ");
    scanf("%s", text);
    create(key);
    strcpy(enc,text);
    process(enc,0);
    printf("Encrypted: %s\n",enc);
    process(enc,1);
    printf("Decrypted: %s\n",enc);
    return 0;
}