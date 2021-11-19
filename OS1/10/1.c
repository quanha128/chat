#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

void* client_thread(void* arg)
{
    char buf[1024];
    int clientfd = (int)(intptr_t)arg;
    int len, i, wlen, er;

    char hbuf[128];
    char sbuf[128];

    struct sockaddr_storage addr;
    socklen_t addlen;
    addlen = sizeof(addr);

    er = getpeername(clientfd, (struct sockaddr*)&addr, &addlen);
    if (er < 0) goto error;

    er = getnameinfo((struct sockaddr*)&addr, addlen, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), 0);
    if (er < 0) goto error;

    len = sprintf(buf, "Your address is %s at port %s\n", hbuf, sbuf);

    /* Write whole len bytes of HTTP request */
    for (i = 0; i < len; ) {
        wlen = write(clientfd, buf + i, len - i);
        if (wlen < 0) goto error;

        i += wlen;
    }    

    close(clientfd);
    return NULL;
    
error:
    fprintf(stderr, "ERROR\n");
    close(clientfd);
    return NULL;
}

int main(int argc, char* argv[])
{
    struct addrinfo hints, *res = NULL, *r;
    const char* portname = "10001";
    int sockfd, er;

    /* Resolve addresses */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET6; /* AF_INET6(IPv6) or AF_INET(IPv4) */
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /* address for bind(2) */
    er = getaddrinfo(NULL, portname, &hints, &res);
    if (er != 0) goto error;

    /* Try to connect to any one of the addresses got */
    for (r = res; r != NULL; r = r->ai_next) {
        sockfd = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
        if (sockfd < 0) continue;

        er = bind(sockfd, r->ai_addr, r->ai_addrlen);
        if (er < 0) {
            close(sockfd);
            sockfd = -1;
            continue;
        }

        /* Successfully connected */
        break;
    }
    if (sockfd < 0) goto error;

    freeaddrinfo(res);
    res = NULL;

    er = listen(sockfd, 5);
    if (er < 0) goto error;

    for (;;) {
        pthread_t thread;
        struct sockaddr_storage addr;
        socklen_t addrlen;
        int clientfd;
    
        addrlen = sizeof(addr);
        er = accept(sockfd, (struct sockaddr*)&addr, &addrlen);
        if (er < 0) goto error;

        clientfd = er;

        pthread_create(&thread, NULL, client_thread, (void*)(intptr_t)clientfd);
        pthread_detach(thread);
    }

    /* Never reached */
    close(sockfd);
    return 0;

 error:
    if (res) freeaddrinfo(res);
    if (sockfd >= 0) close(sockfd);
    return -1;
}