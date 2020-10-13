#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define LOCAL_HOST_PORT 18000

int main(void){

	char http_header[2048]="HTTP/1.1 200 OK\r\n\r\nHELLLLLLLLLLLLLLLLLLOOOOOOOOOOOOOOO WORLDDDDDDDDDDDDDDDDDDDD";
	
	//Create a socket
	int server_socket;
	
	//AF_INET = Address Family - Internet
	//SOCK_STREAM = Stream sockets
	//0 = TCP
	if((server_socket=socket(AF_INET,SOCK_STREAM,0)) < 0){
		printf("socket not created...\n");
		return 0;		
	}


	//specify an address for the socket
	struct sockaddr_in server_addr;
	
	bzero(&server_addr,sizeof(server_addr));
	
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(LOCAL_HOST_PORT);
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);

	if( bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
		printf("Binding error...\n");
		return 0;
	}

	if(listen(server_socket,10) < 0){
		printf("Listen error...\n");
		return 0;
	}

	int client_socket,n;
	char recvline[4096];
	
	while(1){
		printf("Waiting for connection on port %d\n",LOCAL_HOST_PORT);
		
		client_socket=accept(server_socket,(struct sockaddr*)NULL,NULL);
		
		memset(recvline,0,4096*sizeof(char));
		
		printf("Received String: \n");
		
		while( (n=read(client_socket,recvline,4095)) > 0){
			printf("%s",recvline);
			
			if(recvline[n-1]=='\n'){
				break;
			}
			
		}
		
		if(n<0){
			printf("Read Error...\n");
			return 0;
		}
		
		write(client_socket, (char*) http_header, strlen(http_header));
		close(client_socket);
	}

	return 0;
}

