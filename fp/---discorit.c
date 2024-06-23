#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void register_user(int sock, char *username, char *password) {
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "REGISTER %s -p %s", username, password);
    send(sock, message, strlen(message), 0);
    recv(sock, message, BUFFER_SIZE, 0);
    printf("%s", message);
}

void login_user(int sock, char *username, char *password) {
    char message[BUFFER_SIZE];
    snprintf(message, sizeof(message), "LOGIN %s -p %s", username, password);
    send(sock, message, strlen(message), 0);
    recv(sock, message, BUFFER_SIZE, 0);
    printf("%s", message);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;

    if (argc < 6 || strcmp(argv[4], "-p") != 0) {
        fprintf(stderr, "Usage: %s <server_ip> <command> <username> -p <password>\n", argv[0]);
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

    if (strcmp(argv[2], "REGISTER") == 0) {
        register_user(sock, argv[3], argv[5]);
    } else if (strcmp(argv[2], "LOGIN") == 0) {
        login_user(sock, argv[3], argv[5]);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[2]);
        return 1;
    }

    close(sock);
    return 0;
}

