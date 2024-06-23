#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void monitor_chat(int sock, char *username, char *channel, char *room) {
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "MONITOR %s %s %s", username, channel, room);
    send(sock, message, strlen(message), 0);

    while (1) {
        int read_size = recv(sock, message, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            break;
        }
        message[read_size] = '\0';
        printf("%s", message);
    }
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <channel> <room>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }

    monitor_chat(sock, argv[2], argv[3], argv[4]);

    close(sock);
    return 0;
}

