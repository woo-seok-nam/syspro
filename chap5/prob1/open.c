#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc < 2) {
        fprintf(stderr, "How to use: %s [file_name]\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDWR)) == -1)
        printf("File Open Error\n");
    else
        printf("File %s Open Success : %d\n", argv[1], fd);

    close(fd);
    exit(0);
}

