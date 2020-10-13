###This project reads contents from an HTTP localhost Server sent to a client using TCP(SOCK_STREAM).</br >

Run the Server first using: (Remember the port number used)

```
$ cd Server
$ make
$ ./server_http
```

Now navigate to the Client folder from another terminal and find the IP for localhost to pass as arguments.

```
$ cd Client
$ ping localhost #will give the host IP
$ make
$ ./client_http 127.0.0.1 18000 #port num 180000 in this example
```
To read data from online servers, Change port to standard HTTP port 
```
remote_addr.sin_port=htons(SERVER_PORT);
```
