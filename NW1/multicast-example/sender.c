#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 4096
const char GROUP_ADDR[]  = "239.255.1.3"; // group address
const char SENDER_IF[]   = "127.0.0.1";
const unsigned short SERVER_PORTNUM = 9000;
const char MESSAGE[] = "Hello multicast listeners. 002 \n"; // set your student number

int main( int argc, char *argv[]) {
    int sock;
    // create a socket.
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket() failed.\n");
        goto ERROR;
    }

    // initialize
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(GROUP_ADDR);
    server_addr.sin_port = htons(SERVER_PORTNUM);

    // add bridge interface
    // if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_IF, (inet_addr(SENDER_IF)), sizeof(inet_addr(SENDER_IF))) < 0) {
    //     goto ERROR;
    // }

    printf("Message to be sent: %s\n", MESSAGE);
    // send a message to the server
    int message_size = sizeof(MESSAGE);
    if(sendto(sock, MESSAGE, message_size, 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("sendto() failed.\n");
        goto ERROR;
    }

    // close the socket.
    close(sock);
    return(0);

ERROR:
    if(sock >= 0) close(sock);
    return(EXIT_FAILURE);
}