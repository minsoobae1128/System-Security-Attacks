#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUF_SIZE
#define BUF_SIZE 64
#endif

#define IDX_LO  0
#define IDX_HI  14


void print_stdout()
{
    write(1, &stdout, sizeof(stdout));
}

void vuln()
{
    char buffer[BUF_SIZE];
    long idx;

    printf("  idx? ");
    fflush(stdout);
    if (scanf("%ld", &idx) != 1) return;
    if (idx < IDX_LO || idx > IDX_HI) {
        puts("  out of range");
    } else {
        unsigned long v = *(unsigned long *)&buffer[idx * 8];
        printf("  data[%ld] = 0x%016lx\n", idx, v);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    puts("[Input]");
    printf("  > ");
    fflush(stdout);
    read(0, buffer, 256);
}

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin,  NULL, _IONBF, 0);

    puts("Please spwan shell with following shell:");
	puts("/bin/sh");
    vuln();
    return 0;
}
