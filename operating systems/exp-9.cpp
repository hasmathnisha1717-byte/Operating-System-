#include <stdio.h>
#include <string.h>

int main()
{
    char shared_memory[100];

    strcpy(shared_memory, "Hello, shared memory!");

    printf("Data written to shared memory: %s\n", shared_memory);

    return 0;
}