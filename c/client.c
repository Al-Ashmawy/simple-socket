#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>


int main() {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd == -1) {
                perror("Can't create a socket");
                exit(EXIT_FAILURE);
        }

        char* ip = "127.0.0.1";
        struct sockaddr_in addr;
        addr.sin_port = htons(8000);
        addr.sin_family = AF_INET;
        inet_pton(AF_INET, ip, &addr.sin_addr);

        int result = connect(socket_fd, (struct sockaddr*)&addr, sizeof(addr));

        if (result == -1) {
                perror("Connection failed");
                return 1;
        }

        printf("Connection established");

        char msg[] =
                "GET / HTTP/1.1\n"
                "Host: google.com\n"
                "\n";

        if(send(socket_fd, msg, sizeof(msg), 0) == -1) {
                perror("Could not send the message");
                return 1;
        }
        return 0;
}
