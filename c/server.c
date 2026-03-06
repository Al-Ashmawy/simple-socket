#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main() {
        int fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd == -1) {
                perror("Can not create a socket");
                return 1;
        }

        struct sockaddr_in server;
        server.sin_port = htons(8000);
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        memset(server.sin_zero, 0, sizeof(server.sin_zero));

        int result = bind(fd, (struct sockaddr*)&server, sizeof(server));
        if (result == -1) {
                perror("binding failed!");
                return 1;
        }

        listen(fd, 10);

        struct sockaddr_in client;
        unsigned int size = sizeof(client);
        int client_fd = accept(fd,(struct sockaddr*)&client, &size);

        char buffer[1024];
        recv(client_fd, buffer, sizeof(buffer), 0);

        printf("%s\n", buffer);
        return 0;
}
