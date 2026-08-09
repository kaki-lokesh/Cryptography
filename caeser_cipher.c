#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char name[], char cipher[], int key) {
    strcpy(cipher, name);     
    for(int i=0; cipher[i] != '\0'; i++) {
        if(cipher[i] >= 'A' && cipher[i] <= 'Z')
            cipher[i] = ((cipher[i] - 'A' + key) % 26) + 'A';  // Shifts forward
        else if(cipher[i] >= 'a' && cipher[i] <= 'z')
            cipher[i] = ((cipher[i] - 'a' + key) % 26) + 'a';  // Shifts forward
    }
    printf("Cipher Text: %s\n", cipher);
}

int main() {
    char name[100], cipher[100] = "";  // Two arrays
    int key, choice;
    printf("Enter the text: ");
    scanf("%99s", name);
    for(int i = 0; name[i] != '\0'; i++) {
        if(!isalpha(name[i])) {        // Checks if the name is valid
            printf("Name should contain only alphabets\n");
            return 0;
        }
    }
    printf("Enter key: ");
    scanf("%d", &key);
    key %= 26;
    encrypt(name, cipher, key);
    return 0;
}



