#include <stdio.h>
#include <string.h>

int main() {
    char text[100], enc[100], dec[100];
    int rails, i, j, k = 0, len;
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter number of rails: ");
    scanf("%d", &rails);
    len = strlen(text);

    // Encryption
    for(i=0;i<rails;i++)  
        for(j=i;j<len;j+=2*(rails-1))
            enc[k++] = text[j],
            (i!=0 && i!=rails-1 && j+2*(rails-1)-2*i<len) ?
            (enc[k++] = text[j+2*(rails-1)-2*i]) : 0;
    enc[k]='\0';
    printf("Encrypted: %s\n",enc);

    // Decryption
    k=0;
    for(i=0;i<rails;i++) {
        for(j=0;j<len;j++) {
            int row = j%(2*(rails-1));
            if(row>=rails) row=2*(rails-1)-row;
            if(row==i)
                dec[j]=enc[k++];
        }
    }
    dec[len]='\0';
    printf("Decrypted: %s\n",dec);
    return 0;
}