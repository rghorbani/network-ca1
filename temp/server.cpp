#include "server.h"

SG_Server::SG_Server(int port) {
	(*this).port = port;
	FD_ZERO(&client_fds);
    FD_ZERO(&safeSet);
}

void SG_Server::init(char* args[]) {
	/*
	struct sigaction sa;

	struct addrinfo hints, *servinfo, *p;
    
	memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int truVal = 1;
    int status = 0;
    
    while((status = getaddrinfo(NULL, args[1], &hints, &servinfo)) != 0 ) {
    	errx(-1, "%s",gai_strerror(status));
    }
    
    for(p = servinfo; p != NULL; p = p->ai_next) {
    	if (((sockfd) = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
    		continue;
    	}
        
    	if ((status = setsockopt((sockfd), SOL_SOCKET, SO_REUSEADDR, &truVal, sizeof(int))) == -1) {
    		errx(-2, "%s",gai_strerror(status));
    	}
        
    	if (bind((sockfd), p->ai_addr, p->ai_addrlen) == -1) {
    		close((sockfd));
    		continue;
    	}
    	break;
    }
    
    if (p == NULL)  {
    	errx(-3, "%s", "Initialization failed\n");
    }
    
    //Start listening
  	if (listen(sockfd, BACKLOG) == -1) {
    	perror("Listen error");
        errx(-4, "%s", "Listening Failed\n");
    }
    //(sa).sa_handler = sigchld_handler(0); // reap all dead processes
    sigemptyset(&((sa).sa_mask));
    (sa).sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, NULL, &sa) == -1) {
    	errx(-5, "%s", "Handler Failed\n");
    }

    cerr << "[INIT] Server Initilized on port " << port << endl;

    int maxSocket = listener;

    FD_SET(listener, &safeSet);
    FD_SET(0, &safeSet);

    cerr << "[INIT] Server is up and runnig...\n\n";
    */

    ServerSocket server_socket ( 30000 );
    server = server_socket;
}

int SG_Server::working() {
	/*
	int incoming_socket;
	ssize_t recievedBytes;
	struct sockaddr_storage clientAddress;
	char buffer[BUFF_SIZE];
	// string buffer;
	client_fds = safeSet;
	memset(buffer, 0, BUFF_SIZE);

	if(select(maxSocket+1, &client_fds, NULL, NULL, NULL) == -1) {
		//Error select
		cerr << "Error select()" << endl;
		return 3;
	}

	for(int i = 0; i <= maxSocket; i++) {
		if(FD_ISSET(i, &client_fds)) {
			if(i == listener) {
				//c_log("Incoming connection...");
				socklen_t storeSize = sizeof clientAddress ;
				incoming_socket = accept(listener, (struct sockaddr*) &clientAddress, &storeSize);
				if(incoming_socket < 0) {
				  //  c_error("Couldn't establish new connection. accept() error.\n\n");
				    continue;
				}
				
				//arrangements for new client
				//--add to listening set
				FD_SET(incoming_socket, &safeSet);
				//fprintf(stderr, "[LOG] New client established a connection. [%d client(s)]\n", ++numOfClients);
				
				maxSocket = (incoming_socket > maxSocket) ? incoming_socket : maxSocket;
			}
			
			else if(i == 0) {
				//server commands
				recievedBytes = read(i, buffer, BUFF_SIZE);
				printf(">>WHO U TYPING AT?! MIND YOUR OWN BIZ!! K?!<<\n");
            }

            else {
            	bool error = false;
            	while((recievedBytes = recv(i, buffer, BUFF_SIZE, MSG_DONTWAIT)) < 0 ) {
					//Error or DC
					if (errno == EAGAIN || errno == EINTR) {
					    continue;
					}
					
					else {
					    error = true;
					    break;
					}
                }
                if (error) {
					continue;
                }

                if (recievedBytes ==  0) {
					FD_CLR(i, &safeSet);
					//printf("[LOG] A client has been disconnected. [%d client(s)]\n", --numOfClients);
					//Handle disconnected clients
					break;
				}

				char req[REQ_LEN];
				strncpy(req, buffer, REQ_LEN);
				int request = atoi(req);

				//Get requset sender information
				struct sockaddr_storage address;
				socklen_t len = sizeof(address);
				getpeername(i, (struct sockaddr*)&address, &len);

				switch (request) {

					// Register=================
					case REGISTER: {

						break;
					}

					// Login=================
					case LOGIN: {

						break;
					}

					// Change Status=================
					case CHANGESTATUS: {

						break;
					}

					case WHO: {

						break;
					}

					case INVITE: {

						break;
					}

					case ACCEPT: {

						break;
					}
				}
			}
		}
	}
	*/

	ServerSocket new_sock;
	server.accept ( new_sock );
	string received;
	while(true) {
		new_sock >> received;
		new_sock << "done";
	}
}














