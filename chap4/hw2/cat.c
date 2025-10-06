#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int i, line = 1;
    char c;
    int n_option = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-n] file1 [file2 ...]\n", argv[0]);
        exit(1);
    }

    int start = 1;
    if (strcmp(argv[1], "-n") == 0) {
        n_option = 1;
        start = 2;
    }

    for (i = start; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Error opening %s\n", argv[i]);
            continue;
        }

        if (n_option)
            printf("%4d  ", line++);

        while ((c = fgetc(fp)) != EOF) {
            putchar(c);
            if (n_option && c == '\n')
                printf("%4d  ", line++);
        }

        fclose(fp);
    }

    return 0;
}

