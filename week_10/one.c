// Simulate head command
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
    int read_fd, write_fd;
    off_t offset = 0;
    char lu;
    struct stat statFd;
    int counter = 1;
    read_fd = open(argv[1], O_RDONLY);
    stat(argv[1], &statFd);
    if (read_fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    char *line; // variable to store line
    while (lseek(read_fd, offset, SEEK_SET) < statFd.st_size)
    {
        if (read(read_fd, &lu, 1) != -1)
        {
            if (lu == '\0' || counter <= 10)
            {
                if (lu == '\n')
                {
                    counter++;
                }
                printf("%c", lu);
                offset++;
            }
        }
        else
        {
            perror("READ\n");
            close(read_fd);
            close(write_fd);
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}