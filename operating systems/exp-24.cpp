
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[100];

    // Creating a file
    fp = fopen("sample.txt", "w");

    if (fp == NULL) {
        perror("File creation failed");
        return 1;
    }

    printf("File 'sample.txt' created successfully.\n");
    fclose(fp);

    // Opening file for writing
    fp = fopen("sample.txt", "a");

    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }

    printf("File opened for writing.\n");

    // Writing data
    fprintf(fp, "Hello, World!\n");
    printf("Data written to file.\n");
    fclose(fp);

    // Opening file for reading
    fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        perror("File opening failed");
        return 1;
    }

    printf("File opened for reading.\n");
    printf("Data read from file:\n");

    // Reading data
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

    // Deleting the file
    if (remove("sample.txt") == 0) {
        printf("File 'sample.txt' deleted.\n");
    } else {
        perror("File deletion failed");
        return 1;
    }

    return 0;
}
