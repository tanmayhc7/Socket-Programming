#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

//standard HTTP port
#define SERVER_PORT 80

int main(int argc,char *argv[]){
	
	if(argc<2){
		printf("Send server address..\n");//Use ping command to get the ip of any website
		return 0;
	}
	//Create a socket
	int client_socket;
	
	//AF_INET = Address Family - Internet
	//SOCK_STREAM = Stream sockets
	//0 = TCP
	if((client_socket=socket(AF_INET,SOCK_STREAM,0)) < 0){
		printf("socket not created\n");
		return 0;		
	}

	//specify an address for the socket
	struct sockaddr_in remote_addr;

	//zero out the address
	bzero(&remote_addr,sizeof(remote_addr));
	
	remote_addr.sin_family = AF_INET;

	//htons = host to network short ; converts byte order as per the network requires(Lil or big endien)
	remote_addr.sin_port=htons(SERVER_PORT);

	//inet_pton - convert IPv4 and IPv6 addresses from text to binary form
	if( (inet_pton(AF_INET, argv[1], &remote_addr.sin_addr)) <=0){
		printf("inet error...\n");
		return 0;
	}
	
	
	if(0 == connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr))){
		printf("Connected\n");
	} else {
		printf("Not Connected\n");
		return 0;
	}
	
	//receive data from the server
	//GET command to get a page ; '/' to get root home page ; HTTP version 1.1; end of request(\r\n\r\n)
	char request[]="GET / HTTP/1.1 \r\n\r\n";
	char server_response[8192];

//	send(client_socket,request,sizeof(request),0);
	
	if( write(client_socket, request, strlen(request)) != strlen(request)){
		printf("Write Error...\n");
		return 0;
	}
	
	memset(server_response,0,sizeof(server_response));
	
	while(read(client_socket,server_response,sizeof(server_response)) > 0){
		printf("%s\n",server_response);
	}
	
	if(read(client_socket,server_response,sizeof(server_response)) < 0){
		printf("Read Error...\n");
	}

	//close the socket
	close(client_socket);
	
	return 0;
}
