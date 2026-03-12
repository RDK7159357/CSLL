#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    if (signal(SIGINT, SIG_DFL) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    while(1)
        sleep(1);
}