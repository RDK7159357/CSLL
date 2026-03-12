#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int qid, i;
    struct msgbuf message;

    qid = msgget((key_t)10, IPC_CREAT | 0666);

    for(i = 1; i <= 3; i++) {
        message.mtype = i;
        printf("Enter the message to send: ");
        fgets(message.mtext, 100, stdin);
        msgsnd(qid, &message, strlen(message.mtext)+1, 0);
    }
    return 0;
}