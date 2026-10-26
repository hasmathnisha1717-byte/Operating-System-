#include <stdio.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int main()
{
    int produced = 0, consumed = 0;

    while (consumed < MAX_ITEMS)
    {
        if (produced < MAX_ITEMS)
        {
            buffer[in] = produced + 1;

            printf("Produced: %d\n", buffer[in]);

            in = (in + 1) % BUFFER_SIZE;
            produced++;
        }

        if (consumed < produced)
        {
            printf("Consumed: %d\n", buffer[out]);

            out = (out + 1) % BUFFER_SIZE;
            consumed++;
        }
    }

    return 0;
}
