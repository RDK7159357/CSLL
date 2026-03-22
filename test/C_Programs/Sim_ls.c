#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *p;
    char *dir_name = (argc == 2) ? argv[1] : ".";

    dp = opendir(dir_name);
    if(dp == NULL) {
        perror("opendir");
        return 1;
    }
    while((p = readdir(dp)) != NULL) {
        printf("%ld\t%s\n", p->d_ino, p->d_name);
    }
    closedir(dp);
    return 0;
}