#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];

    /* Producer */
    strcpy(message, "Hello, message queue!");

    printf("Producer: Data sent to message queue: %s\n", message);

    /* Consumer */
    printf("Consumer: Data received from message queue: %s\n", message);

    return 0;
}