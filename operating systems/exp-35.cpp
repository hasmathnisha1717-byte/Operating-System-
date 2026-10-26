
#include <stdio.h>
#include <stdlib.h>

struct Block
{
    int blockNumber;
    char data[256];
};

int main()
{
    FILE *file;
    struct Block block;
    int blockNumber;
    int indexBlock[100] = {0};

    file = fopen("indexed_file.txt", "wb+");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter blocks (Enter 0 to exit):\n");

    while (1)
    {
        printf("Block Number: ");
        scanf("%d", &block.blockNumber);

        if (block.blockNumber == 0)
            break;

        if (block.blockNumber < 1 || block.blockNumber >= 100)
        {
            printf("Enter a block number between 1 and 99.\n");
            continue;
        }

        printf("Data: ");
        scanf(" %255[^\n]", block.data);

        fseek(file, 0, SEEK_END);

        indexBlock[block.blockNumber] = ftell(file) + 1;

        fwrite(&block, sizeof(struct Block), 1, file);
    }

    while (1)
    {
        printf("\nEnter block number to read (0 to exit): ");
        scanf("%d", &blockNumber);

        if (blockNumber == 0)
            break;

        if (blockNumber < 1 || blockNumber >= 100 ||
            indexBlock[blockNumber] == 0)
        {
            printf("Block not found.\n");
        }
        else
        {
            fseek(file, indexBlock[blockNumber] - 1, SEEK_SET);

            if (fread(&block, sizeof(struct Block), 1, file) == 1)
            {
                printf("Block Number: %d\n", block.blockNumber);
                printf("Data: %s\n", block.data);
            }
            else
            {
                printf("Error reading block.\n");
            }
        }
    }

    fclose(file);

    return 0;
}
