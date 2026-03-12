#include <stdio.h>
#include <unistd.h>

#define MAXLINE 100

int main(void) {
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    int n;

    if (pipe(fd) < 0)
        printf("pipe error");

    if ((pid = fork()) < 0)
        printf("fork error");
    else if (pid > 0) {        /* parent */
        close(fd[0]);
        write(fd[1], "hello world\n", 12);
        close(fd[1]);
    } else {                   /* child */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
        close(fd[0]);
    }
    return 0;
}