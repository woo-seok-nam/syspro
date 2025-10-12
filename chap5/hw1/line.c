#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

int main(int argc, char *argv[])
{
    int fd, i = 0, j = 0;
    char buf, savedText[MAX_LINES][MAX_LEN];
    ssize_t n;

    if (argc < 2) {
        fprintf(stderr, "How to use: %s file\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror(argv[1]);
        exit(2);
    }

    while ((n = read(fd, &buf, 1)) > 0) {
        if (buf == '\n') {
            savedText[i][j] = '\0';
            i++;
            j = 0;
        } else {
            savedText[i][j++] = buf;
        }
    }
    close(fd);

    char input[50];
    printf("Input: ");
    scanf("%s", input);

    if (strcmp(input, "*") == 0) {
        for (int k = 0; k <= i; k++)
            printf("%d: %s\n", k + 1, savedText[k]);
    } else if (strchr(input, ',') != NULL) {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int line = atoi(token);
            if (line > 0 && line <= i + 1)
                printf("%d: %s\n", line, savedText[line - 1]);
            token = strtok(NULL, ",");
        }
    } else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);
        for (int k = start; k <= end && k <= i + 1; k++)
            printf("%d: %s\n", k, savedText[k - 1]);
    } else {
        int line = atoi(input);
        if (line > 0 && line <= i + 1)
            printf("%d: %s\n", line, savedText[line - 1]);
    }

    return 0;
}

