#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(void){
	//Create a socket
	int network_socket;
	network_socket=socket(AF_INET,SOCK_STREAM,0);

	//specify an address for the socket
	struct sockaddr_in client_addr;
	client_addr.sin_family=AF_INET;
	client_addr.sin_port=htons(9002);
	client_addr.sin_addr.s_addr=INADDR_ANY;

	if(0==connect(network_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))){
		printf("Connected\n");
	} else {
		printf("Not Connected\n");
		return 0;
	}
	
	//receive data from the server
	char server_response[256];
	recv(network_socket,&server_response,sizeof(server_response),0);

	//print out the server reponse
	printf("Data sent by the server: %s \n", server_response);

	//close the socket
	close(network_socket);
	
	return 0;
}
