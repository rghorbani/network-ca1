#ifndef __DFN__
#include <stdio.h>
// #include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <err.h>

#define __DFN__
#endif

//Size sets
#define SIZE 512
#define BACKLOG 10
#define BUFF_SIZE 512
#define NAME_SIZE 16
#define REQ_LEN 3
#define ID_SIZE 3
#define INT_LEN 32
#define CHNK_SIZE 128
#define REQCOMMLEN 30
#define MAX_SEED 40

//Commands
#define REGISTER 1
#define LOGIN 2
#define CHANGESTATUS 3
#define WHO 4
#define INVITE 5
#define ACCEPT 6
#define SELECT 7
#define SEND 8
#define EXIT 9
#define UNKNOWN_COMM -1

//reply MSG
#define MSG100 "It's Ok"
#define MSG101 "Duplicate username or email"
#define MSG102 "Wrong username or password"
#define MSG103 "Wrong status"
#define MSG104 "Not found"
#define MSG105 "Not connected"
#define MSG106 "Not your friend"
#define MSG107 "Not sent"

//Status
#define OFFLINE 0
#define AVAILABLE 1
#define BUSY 2

//server file operation status
#define NOT_FOUND 11
#define NO_SEED 12
#define INIT_TRANS 13
#define CHNK_ERR 14

void sigchld_handler(int s);
