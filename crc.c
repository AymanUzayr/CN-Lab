#include <stdio.h>
#include <string.h>

void main() {
    int i, j, keylen, msglen;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];

    // Input Data and Key
    printf("Enter Data: ");
    scanf("%s", input);
    printf("Enter Key: ");
    scanf("%s", key);

    keylen = strlen(key);
    msglen = strlen(input);
    strcpy(key1, key);

    // Append zeros to input
    for (i = 0; i < keylen - 1; i++) {
        input[msglen + i] = '0';
    }
    input[msglen + keylen - 1] = '\0'; // Null-terminate the string

    // Initialize temp with initial part of input
    strncpy(temp, input, keylen);
    temp[keylen] = '\0';

    // Perform CRC calculation
    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0];
        if (quot[i] == '0') {
            memset(key, '0', keylen);
        } else {
            strcpy(key, key1);
        }
        for (j = 1; j < keylen; j++) {
            rem[j - 1] = (temp[j] == key[j]) ? '0' : '1';
        }
        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }
    quot[msglen] = '\0'; // Null-terminate the quotient string
    rem[keylen - 1] = '\0'; // Null-terminate the remainder string

    // Output quotient, remainder, and final data
    printf("\nQuotient is %s", quot);
    printf("\nRemainder is %s", rem);
    printf("\nFinal data is %s\n", input);
}
