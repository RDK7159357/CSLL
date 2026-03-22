#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd, lines = 0;
    char ch;
    if(argc != 2) {
        printf("Usage: ./head <filename>\n");
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        printf("Error opening file\n");
        return 1;}
    while(read(fd,&ch,1)>0 && lines<10){
        write(1,&ch,1);
        if(ch == '\n') lines++; 
    }
    close(fd);
    return 0;

}