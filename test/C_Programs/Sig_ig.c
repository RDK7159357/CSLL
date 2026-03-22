#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Note: SIGKILL cannot be ignored in real Linux, 
    // but this is how you code SIG_IGN for others (like SIGINT)
    signal(SIGINT, SIG_IGN); 
    printf("I am ignoring Ctrl+C now. Try it!\n");
    while(1) {
        sleep(1);
    }
    return 0;
}