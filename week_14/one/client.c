#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    char buf[100];
    struct sockaddr_in serv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_port = htons(8080);

    connect(sockfd, (struct sockaddr*)&serv, sizeof(serv));

    printf("Enter message: ");
    fgets(buf, 100, stdin);
    write(sockfd, buf, strlen(buf));

    read(sockfd, buf, 100);
    printf("Echo from server: %s\n", buf);

    close(sockfd);
    return 0;
}


// **How to run (two terminals):**
// ```
// # Terminal 1       # Terminal 2
// ./server           ./client