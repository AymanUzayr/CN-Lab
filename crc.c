#include <stdio.h>
#include <string.h>

void main() {
    int i, j, keylen, msglen;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];

    printf("Enter Data: ");
    scanf("%s", input);
    
    printf("Enter Key: ");
    scanf("%s", key);
    
    keylen = strlen(key);
    msglen = strlen(input);
    strcpy(key1, key);

    // Append zeros to the input data
    strcpy(temp, input);
    for (i = 0; i < keylen - 1; i++) {
        strcat(temp, "0");
    }

    // Perform CRC calculation
    for (i = 0; i < msglen; i++) {
        quot[i] = temp[0];
        
        if (quot[i] == '0') {
            strcpy(key, "0000000000000000000000000000000");
        } else {
            strcpy(key, key1);
        }

        for (j = keylen - 1; j > 0; j--) {
            rem[j - 1] = (temp[j] == key[j]) ? '0' : '1';
        }

        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }

    strcpy(rem, temp);

    // Output quotient and remainder
    printf("\nQuotient is %s\n", quot);
    printf("Remainder is %s\n", rem);

    // Output final data
    printf("Final data is: %s%s\n", input, rem);
}
