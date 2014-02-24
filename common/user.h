#include<string>

class SG_User {
private:
	string username;
	string password;
	string email;
	int status;
	bool isLogedIn;
	vector<SG_User> friends;
	vector<SG_User> friendRequests;

public:
	SG_User();
	string getUsername() {return username;}
	string getPassword() {return password;}
	string getEmail() {return email;}
	void loggedIn() {isLogedIn = true;}
	void loggedOff() {isLogedIn = false;}
	bool searchUsername(string );
}