#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(void){	
	
	char server_message[256]=("Reached the Server\n");	

	//Create a server socket
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,0);

	//define server socket
	struct sockaddr_in server_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(9002);
	server_addr.sin_addr.s_addr=INADDR_ANY;//any IP addr on the local machine 

	//bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));

	listen(server_socket,5);

	int client_socket= accept(server_socket,NULL, NULL);

	//send the message	
	send(client_socket, server_message, sizeof(server_message), 0);

	//close the socket
	close(server_socket);
	
	return 0;
}
