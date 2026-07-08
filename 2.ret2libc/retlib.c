#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 12
#endif

const char shell[] = "/bin/sh";

int bof()
{
    char buffer[BUF_SIZE];

    read(0, buffer, 1024);

    return 1;
}

int main(int argc, char **argv)
{
    printf("Try to get Shell!\n");
    printf("Can you get the system(%s)?\n", shell);

    printf("stdout @ %p\n", stdout);

    bof();

    return 1;
}
