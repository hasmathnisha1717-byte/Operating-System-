
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;

    // Open existing file or create a new file
    fp = fopen("foo.txt", "a");

    if (fp == NULL) {
        printf("File opening failed.\n");
        perror("Program");
        return 1;
    }

    printf("File opened successfully.\n");
    printf("File descriptor is not directly displayed using fopen().\n");

    fclose(fp);

    return 0;
}
