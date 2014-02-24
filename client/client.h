#include "../common/defines.h"
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
	int maxSocket;
	int fd;
	int serverFD;
	string serverIP;
	string serverPort;
	fd_set clientFDs, safeSet;

public:
	SG_Client(string, string);
	int connectToServer();
	/*
	void register();
	void login();
	void changeStatus();
	void who();
	void invite();
	void acceptDeny();
	void selectUsername();
	void sendMSG();
	void exit();
	*/
};