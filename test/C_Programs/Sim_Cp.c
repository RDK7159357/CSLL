#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf;
    int fd1, fd2;
    if (argc != 3)
    {
        printf("Usage: ./cp <source> <destination>\n");
        return 1;
    }
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd1 < 0 || fd2 < 0)
    {
        printf("Error opening file\n");
        return 1;
    }
    while (read(fd1, &buf, 1) > 0)
    {
        write(fd2, &buf, 1);
    }
    printf("File copied successfully.\n");
    close(fd1);
    close(fd2);
    return 0;
}