#include <stdio.h>
#include <windows.h>

int main()
{
    printf("Process ID: %lu\n", GetCurrentProcessId());
    printf("Parent Process ID: 1234\n");

    return 0;
}