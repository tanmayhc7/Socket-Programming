# Socket-Programming
### Tip: use `man` command to read about the libraries
## APIs used:
```
1) htons(): converts the unsigned short integer hostshort from host byte order to network byte order. 
2) accept(): extracts the first connection on the queue of pending connections, creates a new socket with the same socket type protocol and address family as the specified socket, and allocates a new file descriptor for that socket.
3) bind(): assigns an address to an unnamed socket.
4) connect(): requests a connection to be made on a socket.
5) listen(): marks a connection-mode socket, specified by the socket argument, as accepting connections.
6) recv(): receives a message from a connection-mode or connectionless-mode socket. It is normally used with connected sockets because      it does not permit the application to retrieve the source address of received data.
7) send(): initiates transmission of a message from the specified socket to its peer. The send() function sends a message only when the     socket is connected (including when the peer of a connectionless socket has been set via connect()).
8) socket(): creates an unbound socket in a communications domain, and returns a file descriptor that can be used in later function         calls that operate on sockets.
9) bind(): assigns an address to an unnamed socket. Sockets created with the socket() function are initially unnamed; they are identified only by their address family.
```
Read about [sys/socket](https://pubs.opengroup.org/onlinepubs/009619199/syssocketh.htm)

## Basic Server Workflow 
**socket[ ]->bind[ ]->listen[ ]->accept[ ]**

## Basic Client Workflow: 
**socket[ ]->connect[ ]->recv[ ]**


