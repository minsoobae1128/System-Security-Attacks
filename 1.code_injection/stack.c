#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 100
#endif

int bof()
{
    char buffer[BUF_SIZE];

    /* Leak: print the runtime address of buffer[] */
    printf("Address of buffer[] inside bof():  0x%.8x\n", (unsigned)buffer);

    gets(buffer);

    return 1;
}

int main(int argc, char **argv)
{
    bof();

    printf("Return successfully without any problem :(\n");
    return 1;
}
