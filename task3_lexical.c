#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if word is a keyword
int isKeyword(char word[]) {
    char *keywords[] = {"int", "float", "if", "else", "while", "return", "char", "double"};
    int total = 8;

    for(int i = 0; i < total; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {

    FILE *fp;
    char ch;
    char word[50];
    int i = 0;

    // Open input file
    fp = fopen("input.txt", "r");

    if(fp == NULL) {
        printf("Error: input.txt file not found\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {

        // If letter or digit, store in word
        if(isalnum(ch)) {
            word[i++] = ch;
        }
        else {

            if(i > 0) {
                word[i] = '\0';

                if(isKeyword(word))
                    printf("%s : Keyword\n", word);
                else if(isdigit(word[0]))
                    printf("%s : Number\n", word);
                else
                    printf("%s : Identifier\n", word);

                i = 0;
            }

            // Check operators
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
                printf("%c : Operator\n", ch);
        }
    }

    fclose(fp);

    return 0;
}