#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int qid, i;
    struct msgbuf buff;

    qid = msgget((key_t)10, IPC_CREAT | 0666);

    for(i = 1; i <= 3; i++) {
        msgrcv(qid, &buff, 100, i, 0);
        printf("Message received from sender is: %s", buff.mtext);
    }
    return 0;
}
```

// **How to run:**
// ```
// # Terminal 1       # Terminal 2
// ./msend            ./mrecv