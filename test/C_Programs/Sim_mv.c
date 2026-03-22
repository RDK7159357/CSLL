#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./mv <source> <destination>\n");
        return 1;
    }
    if(rename(argv[1],argv[2]) == 0) {
        printf("File moved successfully.\n");
    } else {
        perror("Error");
    }
    return 0;

}