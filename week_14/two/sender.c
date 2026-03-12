#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;

    message.msg_type = 1;
    printf("Enter message: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Message sent\n");
    return 0;
}