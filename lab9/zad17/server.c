#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int connfd)
{
	char buff[MAX];
	int n;
	for (;;)
    {
		bzero(buff, MAX);
		read(connfd, buff, sizeof(buff));
		printf("Received: %s", buff);
        if ((strncmp(buff, "50901", 4)) == 0)
        {
            printf("\nServer Exit...\n");
            bzero(buff, MAX);
		    n = 0;
            break;
        }
        else
        {
            bzero(buff, MAX);
		    n = 0;
        }
    }
}

// Driver function
int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Can't create socket!\n");
		exit(0);
	}
	else
		printf("Socket created!\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("Can't bind socket!\n");
		exit(0);
	}
	else
		printf("Socket binded!\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Can't listen!\n");
		exit(0);
	}
	else
		printf("Server listening!\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("Server can't accept!\n");
		exit(0);
	}
	else
		printf("Client accepted!\n");

	// Function for chatting between client and server
    printf("\n");
	func(connfd);

	// After chatting close the socket
	close(sockfd);
}
