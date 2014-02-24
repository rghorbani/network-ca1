#include <iostream>
#include <string>
#include "client.h"

using namespace std;

int main(int argc, char const *argv[]) {
	/*
	if (argc != 3) {
        cerr << "Use this format : <IP address> <port number>";
        return -1;
    }*/
    cout << "Starting App\n";

	SG_Client* client = new SG_Client("127.0.0.1", "3000");

	client->connectToServer();
	
	return 0;
}