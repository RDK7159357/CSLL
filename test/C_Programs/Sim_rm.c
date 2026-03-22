#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./rm <filename>\n");
        return 1;
    }
    if(remove(argv[1]) == 0) {
        printf("File %s removed successfully.\n", argv[1]);
    } else {
        perror("Error");
    }
    return 0;
}