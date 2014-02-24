#include "client.h"

SG_Client::SG_Client(string ip, string port) {
	
	serverIP = ip;
	serverPort = port;
}

int SG_Client::connectToServer() {

	int fd;
    struct addrinfo hints ,*server, *p;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    int rv;
    if((rv =getaddrinfo(serverIP.c_str(), serverPort.c_str(), &hints, &server)) != 0 ) {
        cerr << "Error connecting to server.\n";
        cerr << "code: " << gai_strerror(rv) << endl;
        return -1;
    }
    for(p = server; p != NULL; p = p->ai_next) {
        if ((fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }
        if (connect(fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(fd);
            continue;
        }
        break;
    }
    if (p == NULL) {
        return 2;
    }
    if(fd == -1){
        cerr << "[ERR] Couldn't Create socket.\n";
        exit(1);
    }
    
    FD_SET(fd, &safeSet);
    if(fd > maxSocket)
        maxSocket = fd;
    connected = true;
    cout << "[LOG] Connected to a server at " << serverIP << ":" << serverPort << endl;

    (*this).fd = fd;
}