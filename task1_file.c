#include <stdio.h>

int main() {

    FILE *fp;
    char data[100];

    // Create and write to file
    fp = fopen("sample.txt", "w");

    if(fp == NULL){
        printf("File cannot be created");
        return 1;
    }

    printf("Enter text to write in file: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp,"%s",data);

    fclose(fp);

    // Append data
    fp = fopen("sample.txt","a");

    printf("Enter text to append: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp,"%s",data);

    fclose(fp);

    // Read file
    fp = fopen("sample.txt","r");

    printf("\nFile Content:\n");

    while(fgets(data,sizeof(data),fp)!=NULL){
        printf("%s",data);
    }

    fclose(fp);

    return 0;
}