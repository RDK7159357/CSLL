#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    char buf;
    if(argc !=2){
        printf("Usage: ./cat <>filename>\n");
        return 1;
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        printf("Error opening file\n");
        return 1;   
    }
    while(read(fd, &buf, 1)>0){
        write(1, &buf, 1);
    }
 close(fd);
 return 0;
}