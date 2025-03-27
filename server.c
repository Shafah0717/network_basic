#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server, cli;
    int cli_len;
    int sd, n, i, len;
    int data, temp;
    char buffer[100];

    // Create a socket
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket failed:");
        exit(1);
    }

    // Initialize the server structure
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));  // Port number passed as argument
    server.sin_addr.s_addr = htonl(INADDR_ANY);  // Bind to all available interfaces

    // Bind the socket to an address and port
    if(bind(sd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("bind failed:");
        exit(1);
    }

    // Listen for incoming connections
    listen(sd, 5);

    // Accept a connection from the client
    if((data = accept(sd, (struct sockaddr *)&cli, &cli_len)) < 0) {
        perror("accept failed:");
        exit(1);
    }

    // Read the message sent by the client
    read(data, buffer, sizeof(buffer));
    len = strlen(buffer);

    // Reverse the string
    for(i = 0; i <= len/2; i++) {
        temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
    }

    // Send the reversed string back to the client
    write(data, buffer, sizeof(buffer));

    // Close the connection and the socket
    close(data);
    close(sd);
}
