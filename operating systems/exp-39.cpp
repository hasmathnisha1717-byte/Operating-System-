 
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
    int pageFaults = 0;

    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);

    int i, j, k, page, pageFound;
    int optimalPage, farthestDistance, futureDistance;

    for (i = 0; i < MAX_FRAMES; i++)
        frames[i] = -1;

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
                break;
            }
        }

        if (!pageFound)
        {
            printf("Page %d -> ", page);
            optimalPage = -1;

            for (j = 0; j < MAX_FRAMES; j++)
            {
                if (frames[j] == -1)
                {
                    optimalPage = j;
                    break;
                }
            }

            if (optimalPage == -1)
            {
                farthestDistance = -1;

                for (j = 0; j < MAX_FRAMES; j++)
                {
                    futureDistance = 0;

                    for (k = i + 1; k < n; k++)
                    {
                        if (referenceString[k] == frames[j])
                            break;

                        futureDistance++;
                    }

                    if (k == n)
                    {
                        optimalPage = j;
                        break;
                    }

                    if (futureDistance > farthestDistance)
                    {
                        farthestDistance = futureDistance;
                        optimalPage = j;
                    }
                }
            }

            if (frames[optimalPage] == -1)
                printf("Load into an empty frame: ");
            else
                printf("Replace %d with %d: ",
                       frames[optimalPage], page);

            frames[optimalPage] = page;

            printFrames(frames, MAX_FRAMES);
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
