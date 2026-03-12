#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile1", 10);
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, (void*)0, 0);

    int child = fork();

    if(child > 0) {  /* parent - writes */
        printf("Write Data: ");
        fgets(str, 1024, stdin);
        printf("parent: Data written in memory: %s", str);
    } else {         /* child - reads */
        sleep(1);
        printf("child: Data read from memory: %s", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}