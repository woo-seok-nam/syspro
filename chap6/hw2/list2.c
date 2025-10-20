#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opt_i = 0, opt_p = 0, opt_q = 0;

char type(mode_t m) {
    if (S_ISDIR(m)) return 'd';
    if (S_ISREG(m)) return '-';
    if (S_ISLNK(m)) return 'l';
    if (S_ISCHR(m)) return 'c';
    if (S_ISBLK(m)) return 'b';
    if (S_ISFIFO(m)) return 'p';
    if (S_ISSOCK(m)) return 's';
    return '?';
}

char *perm(mode_t mode) {
    static char p[10];
    strcpy(p, "---------");
    for (int i = 0; i < 3; i++) {
        if (mode & (S_IRUSR >> i * 3)) p[i * 3] = 'r';
        if (mode & (S_IWUSR >> i * 3)) p[i * 3 + 1] = 'w';
        if (mode & (S_IXUSR >> i * 3)) p[i * 3 + 2] = 'x';
    }
    return p;
}

void print_entry(const char *dir, struct dirent *d) {
    struct stat st;
    char path[BUFSIZ];
    sprintf(path, "%s/%s", dir, d->d_name);
    if (lstat(path, &st) < 0) {
        perror(path);
        return;
    }
    if (opt_i) printf("%8ld ", (long)d->d_ino);
    if (opt_p) printf("%c%s ", type(st.st_mode), perm(st.st_mode));
    if (opt_q) printf("\"%s\"\n", d->d_name);
    else printf("%s\n", d->d_name);
}

int main(int argc, char *argv[]) {
    char *dir = ".";
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (strchr(argv[i], 'i')) opt_i = 1;
            if (strchr(argv[i], 'p')) opt_p = 1;
            if (strchr(argv[i], 'Q')) opt_q = 1;
        } else dir = argv[i];
    }
    DIR *dp;
    struct dirent *d;
    if ((dp = opendir(dir)) == NULL) {
        perror("opendir");
        exit(1);
    }
    while ((d = readdir(dp)) != NULL)
        print_entry(dir, d);
    closedir(dp);
    return 0;
}

