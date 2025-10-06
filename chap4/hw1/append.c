#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c;
    FILE *fp1, *fp2;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        exit(1);
    }

    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        exit(2);
    }

    if ((fp2 = fopen(argv[2], "a")) == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[2]);
        exit(3);
    }

    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp2);

    fclose(fp1);
    fclose(fp2);

    printf("Appended contents of %s to %s successfully.\n", argv[1], argv[2]);
    return 0;
}

