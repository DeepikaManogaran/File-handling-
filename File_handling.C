#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;
    char data[100];

    // 1. CREATE & WRITE TO FILE
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }
    printf("Enter text to write into the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data written to file successfully.\n");

    // 2. READ FILE
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error reading file.\n");
        return 1;
    }
    printf("\nReading data from file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    // 3. APPEND DATA TO FILE
    fp = fopen("example.txt", "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }
    printf("\nEnter text to append to the file:\n");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("Data appended to file successfully.\n");

    // 4. READ FILE AGAIN
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error reading file again.\n");
        return 1;
    }
    printf("\nFinal contents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);

    return 0;
}
