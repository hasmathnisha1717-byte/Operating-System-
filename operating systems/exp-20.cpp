
#include <stdio.h>

int data = 0;

int main() {
    int i;

    // Reader operation
    for (i = 0; i < 10; i++) {
        printf("Reader reads data: %d\n", data);

        // Writer operation
        data++;
        printf("Writer writes data: %d\n", data);
    }

    return 0;
}

