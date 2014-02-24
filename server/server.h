#include "../common/defines.h"
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/dir.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

class SG_Server {
private:
	int listener;
	int maxSocket;
	int sockfd;
	string port;
	fd_set client_fds, safeSet;

public:
	SG_Server(string);
	void init(char* args[]);
};