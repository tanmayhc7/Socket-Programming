#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc,char *argv[]){
	
	char *address;
	address=argv[1];

	//Create a socket
	int client_socket;
	client_socket=socket(AF_INET,SOCK_STREAM,0);

	//specify an address for the socket
	struct sockaddr_in remote_addr;
	remote_addr.sin_family=AF_INET;
	remote_addr.sin_port=htons(80);
	inet_aton(address, &remote_addr.sin_addr.s_addr);

	if(0==connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr))){
		printf("Connected\n");
	} else {
		printf("Not Connected\n");
		return 0;
	}
	
	//receive data from the server
	char request[]="GET / HTTP/1.1 \r\n\r\n";
	char server_response[4096];

	send(client_socket,request,sizeof(request),0);
	recv(client_socket,&server_response,sizeof(server_response),0);

	//print out the server reponse
	printf("Data sent by the server: %s \n", server_response);

	//close the socket
	close(client_socket);
	
	return 0;
}
