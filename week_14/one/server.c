#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd, connfd;
    char buf[100];
    struct sockaddr_in serv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = 0;
    serv.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr*)&serv, sizeof(serv));
    listen(sockfd, 5);

    printf("Server waiting...\n");
    connfd = accept(sockfd, NULL, NULL);

    int n = read(connfd, buf, 100);
    write(connfd, buf, n);  /* echo back */
    printf("Server echoed: %s\n", buf);

    close(connfd);
    close(sockfd);
    return 0;
}