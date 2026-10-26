
#include <stdio.h>
#include <stdlib.h>

#define SOURCE "C:/Users/itssk/OneDrive/Desktop/sasi.txt"
#define DEST "C:/Users/itssk/OneDrive/Desktop/sk.txt"

void create()
{
    FILE *fp = fopen(SOURCE, "w");

    if (fp == NULL)
    {
        printf("File creation failed.\n");
        return;
    }

    fclose(fp);
    printf("File created successfully.\n");
}

void copy()
{
    FILE *src, *dest;
    char buffer[4096];
    size_t bytesRead;

    src = fopen(SOURCE, "rb");

    if (src == NULL)
    {
        printf("Source file not found.\n");
        return;
    }

    dest = fopen(DEST, "wb");

    if (dest == NULL)
    {
        printf("Cannot create destination file.\n");
        fclose(src);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        if (fwrite(buffer, 1, bytesRead, dest) != bytesRead)
        {
            printf("Error copying file.\n");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");
}

void deleteFile()
{
    if (remove(SOURCE) == 0)
        printf("File deleted successfully.\n");
    else
        printf("File deletion failed.\n");
}

int main()
{
    int n;

    printf("1. Create\n");
    printf("2. Copy\n");
    printf("3. Delete\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            deleteFile();
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
