// #include "ServerSocket.h"
#include "server.h"
#include "SocketException.h"
#include <string>

using namespace std;

int main ( int argc, char* argv[] ) {
	/*
	std::cout << "running....\n";

	try {
		// Create the socket
		ServerSocket server ( 30000 );

		while ( true ) {

			ServerSocket new_sock;
			server.accept ( new_sock );

			try {
				while ( true ) {
					std::string data;
					new_sock >> data;
					new_sock << data;
				}
			} catch ( SocketException& ) {}

		}
	} catch ( SocketException& e ) {
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}
	*/

	/*
	if(argc != 2) {
        cerr << "Usage : <PortNumber>";
		return -1;
	}*/

	SG_Server server(3000);

	server.init(argv);

	while(server.working()) {
		
	}

	return 0;
}