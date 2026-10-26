
#include <stdio.h>

int main()
{
    int n;
    FILE *fp, *src, *dest;
    char ch;

    printf("1. Create\n");
    printf("2. Copy\n");
    printf("3. Delete\n");
    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            fp = fopen("sasi.txt", "w");

            if (fp != NULL)
            {
                printf("File created successfully");
                fclose(fp);
            }
            else
                printf("File creation failed");
            break;

        case 2:
            src = fopen("sasi.txt", "r");

            if (src == NULL)
            {
                printf("Source file not found");
                break;
            }

            dest = fopen("sk.txt", "w");

            if (dest == NULL)
            {
                printf("Destination file error");
                fclose(src);
                break;
            }

            while ((ch = fgetc(src)) != EOF)
                fputc(ch, dest);

            fclose(src);
            fclose(dest);

            printf("File copied successfully");
            break;

        case 3:
            if (remove("sasi.txt") == 0)
                printf("File deleted successfully");
            else
                printf("File deletion failed");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
