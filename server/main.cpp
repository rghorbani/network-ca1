#include <iostream>
#include <string>
#include "server.h"

using namespace std;

int main(int argc, char *argv[]) {
	/*
	if(argc != 2) {
        cerr << "Usage : <PortNumber>";
		return -1;
	}*/

	SG_Server* server = new SG_Server("3000");

	server->init(argv);

	return 0;
}