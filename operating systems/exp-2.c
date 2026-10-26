#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Enter source filename: ");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");

    if (fptr1 == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    printf("Enter destination filename: ");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");

    if (fptr2 == NULL)
    {
        printf("Cannot create file!\n");
        return 0;
    }

    c = fgetc(fptr1);

    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("File copied successfully!");

    fclose(fptr1);
    fclose(fptr2);

    return 0;
}