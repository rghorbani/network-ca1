#include "client.h"

SG_Client::SG_Client(string ip, int port) {
	
	serverIP = ip;
	serverPort = port;
}

int SG_Client::connectToServer() {

	/*
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
	*/

	ClientSocket client_socket ( "localhost", 3000 );
	client = client_socket;
}

int SG_Client::working() {

	get_command();
	/*
	client_fds = safeSet;
	if(select(maxSocket+1, &client_fds, NULL, NULL, NULL) == -1){
		//Error select
		cerr << "Error select()" << endl;
		return 1;
	}
	int i;
	char reqstr[REQ_LEN];

	for(i = 0; i <= maxSocket; i++) {
		if(FD_ISSET(i, &client_fds)) {
			if(i == 0) {
				get_command();
				cout << endl;
			} else if(i == server_fd) {

				ssize_t rb;
				while ((rb = recv(i, from_server, sizeof(from_server), MSG_DONTWAIT)) < 0) {
					if (errno == EAGAIN || errno == EINTR) {
						continue;
					}
					break;
				}
				if (rb == 0) {
					FD_CLR(i, &safeSet);
					continue;
				}
				memset(reqstr, '\0', REQ_LEN);
				memcpy(reqstr, from_server, REQ_LEN*sizeof(char));
				int request = atoi(reqstr);

				switch(request) {

					case GET: {
						break;
					}

					default: {
						cout << "Unknown Request" << endl;
						break;
					}
				}
			}
		}
	}
	*/
	return 0;
}

int SG_Client::get_command() {

	string reqType;
	cin >> reqType;
	
	if(reqType == "Register") {

		string username, password, email;
		cin >> username >> password >> email;
		
		register_user(username, password, email);
	}

	else if(reqType == "Login") {

		string username, password;
		cin >> username >> password;

		login(username, password);
	}

	else if(reqType == "ChangeStatus") {

		string status;
		cin >> status;

		changeStatus(status);
	}

	else if(reqType == "Who") {

		string str;
		cin >> str;

		who(str);
	}

	else if(reqType == "Invite") {

		string username;
		cin >> username;

		invite(username);
	}

	else if(reqType == "Accept" || reqType == "Deny") {

		string username;
		cin >> username;

		acceptDeny(username);
	}

	else if(reqType == "Select") {

		string username;
		cin >> username;

		selectUsername(username);
	}

	else if(reqType == "Send") {

		string msg;
		cin >> msg;

		sendMSG(msg);
	}

	else if(reqType == "Exit") {

		sg_exit();
		return 1;
	}

	else {
		cout << "Wrong Command" << endl;
	}
	return 0;
}

void SG_Client::register_user(string username, string password, string email) {

	client << username << password << email;

	string received;
	client >> received;
	if(received == "100") {
		cout << MSG100 <<" - " << "You are logged in as " << username << "." << endl;
	} else if(received == "101") {
		if(received == "username") {
			cout << "Duplicate username." << endl;
		} else if(received == "email") {
			cout << "Duplicate email." << endl;
		}
	}
}

void SG_Client::login(string username, string password) {

	client << username << password;

	string received;
	client >> received;
	if(received == "100") {
		loggedIn = true;
		cout << MSG100 <<" - " << "You are logged in as " << username << "." << endl;
	} else if(received == "102") {
		cout << MSG102 << endl;
	}
}

void SG_Client::changeStatus(string status) {
	
	if(loggedIn) {
		client << status;

		string received;
		client >> received;
		if(received == "100") {
			cout << MSG100 <<" - " << "Status changed." << endl;
		} else if(received == "103") {
			cout << MSG103 << endl;
		}
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::who(string str) {
	
	if(loggedIn) {
		client << str;
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::invite(string username) {

	if(loggedIn) {
		client << username;

		string received;
		client >> received;
		if(received == "100") {

		} else {

		}
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::acceptDeny(string username) {

	if(loggedIn) {
		client << username;

		string received;
		client >> received;
		if(received == "100") {
			cout << MSG100 <<" - " << username << " approved." << endl;
		} else if(received == "104") {
			cout << MSG104 <<" - " << username << " not found on your request's list" << endl;
		}
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::selectUsername(string username) {

	if(userSelected) {
		client << username;

		string received;
		client >> received;
		if(received == "100") {
			cout << MSG100 <<" - " << username << " selected." << endl;
		} else {
			cout << "There was a problem selecting " << username << "." << endl;
		}
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::sendMSG(string msg) {
	
	if(loggedIn) {
		if(userSelected) {
			client << msg;
			
			string received;
			client >> received;
			if(received == "100") {
				cout << MSG100 <<" - " << "Your message send successfully." << endl;
			} else {
				cout << "There was a problem sending MSG." << endl;
			}
		} else {
			cout << "Please select a user first." << endl;
		}
	} else {
		cout << "Please logIn first." << endl;
	}
}

void SG_Client::sg_exit() {
	//
}










