#include <stdio.h>
#include <string.h>

// Function for compression
void compress(char str[]) {
    int count;
    int n = strlen(str);

    printf("Compressed Output: ");

    for(int i = 0; i < n; i++) {

        count = 1;

        while(i < n-1 && str[i] == str[i+1]) {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
    }

    printf("\n");
}

// Function for decompression
void decompress(char str[]) {

    printf("Decompressed Output: ");

    for(int i = 0; str[i] != '\0'; i++) {

        if(isalpha(str[i])) {

            char ch = str[i];
            int count = str[i+1] - '0';

            for(int j = 0; j < count; j++) {
                printf("%c", ch);
            }

            i++;
        }
    }

    printf("\n");
}

int main() {

    char input[100];
    char compressed[100];

    printf("Enter string to compress: ");
    scanf("%s", input);

    compress(input);

    printf("\nEnter compressed string to decompress: ");
    scanf("%s", compressed);

    decompress(compressed);

    return 0;
}