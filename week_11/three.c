#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    if (signal(SIGKILL, SIG_IGN) == SIG_ERR)
        printf("\ncan't catch SIGKILL\n");
    while(1)
        sleep(1);
}