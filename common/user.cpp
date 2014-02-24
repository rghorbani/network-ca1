#include "user.h"

SG_User::SG_User(string username, string password, string email) {
	this.username = username;
	this.password = password;
	this.email = email;
}

SG_User* SG_User::searchUsername(string username) {
	
	SG_User* user = NULL;

	for(int i = 0 ;i < friends.size(); ++i) {
		if(friends[i].getUsername() == username)
			user = &friends[i];
	}

	for (int i = 0; i < friendRequests.size(); ++i) {
		if(friendRequests[i].getUsername() == username)
			user = &friendRequests[i];
	}

	return user;
}