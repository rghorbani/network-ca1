#include "server.h"

SG_Server::SG_Server(string port) {
	(*this).port = port;
	FD_ZERO(&client_fds);
    FD_ZERO(&safeSet);
}

void SG_Server::init(char* args[]) {

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
    (sa).sa_handler = sigchld_handler(0); // reap all dead processes
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

}














