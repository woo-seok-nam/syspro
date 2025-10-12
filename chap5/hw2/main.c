#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char *lines[MAX_LINES];
    char buffer[MAX_LEN];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        lines[count] = strdup(buffer);
        count++;
    }
    fclose(fp);

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}

