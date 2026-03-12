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

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Received message: %s", message.msg_text);
    printf("Message received successfully!\n");
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}


// **How to run:**
// ```
// # Terminal 1            # Terminal 2
// gcc sender.c -o sender  gcc receiver.c -o receiver
// ./sender                ./receiver
// Enter message: Hello!   Received message: Hello!
// Message sent            Message received successfully!