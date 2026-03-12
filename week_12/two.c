#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/myfifo"
#define MAXSIZE 100

int main() {
    int fd, n;
    char w[MAXSIZE];

    mkfifo(FIFO_NAME, 0755);
    fd = open(FIFO_NAME, O_WRONLY);

    printf("Producer:\n");
    while(1) {
        read(0, w, MAXSIZE);
        n = write(fd, w, MAXSIZE);
        if(n > 0)
            printf("Producer sent: %s", w);
    }
    return 0;
}