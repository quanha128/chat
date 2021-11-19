#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct hostent *hp;
const int BUF_SIZE = 256;
// char SERVER_IP[] = ;
const unsigned short SERVER_PORTNUM = 9000;
char MESSAGE[256];

void error_handler(const char* message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sock;
    // create a socket
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error_handler("socket() failed.\n");
    }

    //initialize
    hp = gethostbyname("localhost");
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(uint32_t *)(hp->h_addr);
    server_addr.sin_port = htons(SERVER_PORTNUM);

    //connect to the server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        error_handler("connect() failed.\n");
    }

    //send a message to the server
    int total_sent_size;
    int received_bytes, total_received_bytes;
    char buf[BUF_SIZE];
    while(1) {
        fgets(MESSAGE, 256, stdin);
        int message_size = strlen(MESSAGE);
        for(total_sent_size = 0; total_sent_size < message_size; ) {
            int sent_size;
            if((sent_size = send(sock, &MESSAGE[total_sent_size], message_size - total_sent_size, 0)) < 0) {
                close(sock); error_handler("send() failed.\n");
            }
            total_sent_size += sent_size;
        }
        received_bytes = 0, total_received_bytes = 0;
    }
    printf("Received message: ");
    while(1) {
        //received messages from the server
        if((received_bytes = recv(sock, buf, sizeof(buf)-1, 0)) < 0) {
            close(sock); error_handler("recv() failed.\n");
        } else if(received_bytes == 0) {break;}
        total_received_bytes += received_bytes;
        buf[received_bytes] = '\0';
        printf("%s", buf);
    }
    printf("\n");

    //close the socket
    close(sock);
    exit(0);
}