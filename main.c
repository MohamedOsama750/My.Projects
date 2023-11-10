#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] + key - 'a' + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + key - 'A' + 26) % 26 + 'A';
        }
    }
}

void decrypt(char message[], int key) {
    encrypt(message, 26 - key);
}

int main() {
    char message[100];
    int key;
    int choice;

    while (1) {
        printf("Enter your message: ");
        scanf(" %[^\n]s", message);

        printf("Original Message: %s\n", message);

        printf("Enter 1 to encrypt, 2 to decrypt, or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else if (choice == 1 || choice == 2) {
            printf("Enter the encryption/decryption key: ");
            scanf("%d", &key);

            if (choice == 1) {
                encrypt(message, key);
                printf("Encrypted Message: %s\n", message);
            } else {
                decrypt(message, key);
                printf("Decrypted Message: %s\n", message);
            }
        } else {
            printf("Invalid choice. Please enter 1 to encrypt, 2 to decrypt, or 0 to exit.\n");
        }

        while ((getchar()) != '\n');
    }

    return 0;
}
