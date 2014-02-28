#ifndef SG_Client_class
#define SG_Client_class

#include "ClientSocket.h"
#include "defines.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/param.h>

using namespace std;

class SG_Client {
private:
	bool connected;
	bool loggedIn;
	bool userSelected;
	/*
	int maxSocket;
	int fd;
	int serverFD;
	*/
	ClientSocket client;
	string serverIP;
	int serverPort;
	fd_set clientfds, safeSet;

public:
	// SG_Client();
	SG_Client(string, int);
	int connectToServer();
	int working();
	int get_command();

	void register_user(string, string, string);
	void login(string, string);
	void changeStatus(string);
	void who(string);
	void invite(string);
	void acceptDeny(string);
	void selectUsername(string);
	void sendMSG(string);
	void sg_exit();
	
};

#endif