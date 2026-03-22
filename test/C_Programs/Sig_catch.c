#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int sig){
    if(sig==SIGINT){
        printf("Caught SIGINT (Ctrl+C). Exiting gracefully.\n");
        // _exit(0);  // Exit immediately without cleanup
    }

}

int main(){
    signal(SIGINT, sig_handler);
    printf("Running... Press Ctrl+C to trigger SIGINT.\n");
    while(1){
        sleep(1);  // Sleep to reduce CPU usage and allow signal handling   
    }
    return 0;
}