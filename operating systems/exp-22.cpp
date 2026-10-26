
#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

void initializeMemory() {
    int i;
    for (i = 0; i < MAX_MEMORY; i++) {
        memory[i] = -1;
    }
}

void displayMemory() {
    int i, j;

    printf("\nMemory Status:\n");

    for (i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == -1) {
            j = i;

            while (j < MAX_MEMORY && memory[j] == -1) {
                j++;
            }

            printf("Free memory block %d-%d\n", i, j - 1);
            i = j - 1;
        }
    }
}

void allocateMemory(int processId, int size) {
    int i, j;
    int bestStart = -1;
    int bestSize = MAX_MEMORY + 1;
    int blockSize;

    // Find the smallest suitable free block
    i = 0;

    while (i < MAX_MEMORY) {
        if (memory[i] == -1) {
            j = i;

            while (j < MAX_MEMORY && memory[j] == -1) {
                j++;
            }

            blockSize = j - i;

            if (blockSize >= size && blockSize < bestSize) {
                bestSize = blockSize;
                bestStart = i;
            }

            i = j;
        } else {
            i++;
        }
    }

    // Allocate memory
    if (bestStart != -1) {
        for (i = bestStart; i < bestStart + size; i++) {
            memory[i] = processId;
        }

        printf("Allocated memory block %d-%d to Process %d\n",
               bestStart, bestStart + size - 1, processId);
    } else {
        printf("Memory allocation for Process %d failed.\n", processId);
    }
}

void deallocateMemory(int processId) {
    int i;

    for (i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == processId) {
            memory[i] = -1;
        }
    }

    printf("Memory released by Process %d\n", processId);
}

int main() {
    initializeMemory();

    displayMemory();

    allocateMemory(1, 200);
    displayMemory();

    allocateMemory(2, 300);
    displayMemory();

    deallocateMemory(1);
    displayMemory();

    allocateMemory(3, 400);
    displayMemory();

    return 0;
}
