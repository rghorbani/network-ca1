#include "client.h"
// #include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char* argv[]) {
	/*
	try {

		ClientSocket client_socket ( "localhost", 30000 );

		std::string reply;

		try	{
			client_socket << "Test message.";
			client_socket >> reply;
		}
		catch ( SocketException& ) {}

		std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

	} catch ( SocketException& e ) {
			std::cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
	*/

	if (argc != 3) {
		cerr << "Use this format : <IP address> <port number>";
		return -1;
   	}
	cout << "Starting App\n";

	SG_Client client("127.0.0.1", 3000);

	client.connectToServer();

	while(client.working() == 0) {

	}
	
	return 0;
}