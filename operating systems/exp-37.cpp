
#include <stdio.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }

    printf("\n");
}

int main()
{
    int frames[MAX_FRAMES];
    int usageHistory[MAX_FRAMES];
    int pageFaults = 0;

    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);

    int i, j, k, page, pageFound, lruPage, replacedPage;

    for (i = 0; i < MAX_FRAMES; i++)
    {
        frames[i] = -1;
        usageHistory[i] = 0;
    }

    printf("Reference String: ");

    for (i = 0; i < n; i++)
        printf("%d ", referenceString[i]);

    printf("\n\nPage Replacement Order:\n");

    for (i = 0; i < n; i++)
    {
        page = referenceString[i];
        pageFound = 0;

        for (j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == page)
            {
                pageFound = 1;
                usageHistory[j] = 0;

                for (k = 0; k < MAX_FRAMES; k++)
                {
                    if (k != j && frames[k] != -1)
                        usageHistory[k]++;
                }

                break;
            }
        }

        if (!pageFound)
        {
            printf("Page %d -> ", page);

            lruPage = -1;

            for (j = 0; j < MAX_FRAMES; j++)
            {
                if (frames[j] == -1)
                {
                    lruPage = j;
                    break;
                }
            }

            if (lruPage == -1)
            {
                lruPage = 0;

                for (j = 1; j < MAX_FRAMES; j++)
                {
                    if (usageHistory[j] > usageHistory[lruPage])
                        lruPage = j;
                }
            }

            replacedPage = frames[lruPage];
            frames[lruPage] = page;

            if (replacedPage == -1)
                printf("Load into an empty frame: ");
            else
                printf("Replace %d with %d: ", replacedPage, page);

            usageHistory[lruPage] = 0;

            for (j = 0; j < MAX_FRAMES; j++)
            {
                if (j != lruPage && frames[j] != -1)
                    usageHistory[j]++;
            }

            printFrames(frames, MAX_FRAMES);
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
