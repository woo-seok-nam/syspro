#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

extern char **environ;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-e [env_name]] [-u] [-g] [-i] [-p]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                char *val = getenv(argv[i + 1]);
                if (val)
                    printf("%s = %s\n", argv[i + 1], val);
                else
                    printf("Environment variable '%s' not found.\n", argv[i + 1]);
                i++;
            } else {
                for (char **env = environ; *env != NULL; env++)
                    printf("%s\n", *env);
            }
        }
        else if (strcmp(argv[i], "-u") == 0) {
            printf("Real User ID: %d (%s)\n", getuid(), getpwuid(getuid())->pw_name);
            printf("Effective User ID: %d (%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
        }
        else if (strcmp(argv[i], "-g") == 0) {
            printf("Real Group ID: %d (%s)\n", getgid(), getgrgid(getgid())->gr_name);
            printf("Effective Group ID: %d (%s)\n", getegid(), getgrgid(getegid())->gr_name);
        }
        else if (strcmp(argv[i], "-i") == 0) {
            printf("Process ID: %d\n", getpid());
        }
        else if (strcmp(argv[i], "-p") == 0) {
            printf("Parent Process ID: %d\n", getppid());
        }
        else {
            printf("Unknown option: %s\n", argv[i]);
        }
    }
    return 0;
}

