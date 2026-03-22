#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd, count = 1;
    char ch;
    fd = open(argv[1], O_RDONLY);
    printf("%d ", count++);
    while(read(fd, &ch, 1) > 0) {
        printf("%c", ch);
        if(ch == '\n') {
            printf("%d ", count++);
        }
    }
    close(fd);
    return 0;
}