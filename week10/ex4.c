#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "sys/types.h"

#define SIZE 777

int main() {
    struct dirent *dp;
    char path[SIZE];

    DIR *dirp = opendir("./tmp/");
    struct stat st;
    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        memset(path, 0, sizeof(path));
        strcat(path, "./tmp/");
        strcat(path, dp->d_name);
        stat(path, &st);
        if (st.st_nlink >= 2) {
            char res[SIZE];
            char buffer[SIZE];
            printf("Hard links to %s: \n", dp->d_name);
            sprintf(res, "find ~ -inum %lu", dp->d_ino);
            FILE *fp = popen(res, "r");
            while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
                printf("%s", buffer);
            }
            printf("\n");
            fclose(fp);
        }
    }

    closedir(dirp);
    return 0;
}