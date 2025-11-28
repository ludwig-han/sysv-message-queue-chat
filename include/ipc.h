#ifndef IPC_H
#define IPC_H

#define MSG_KEY_PATH "."
#define MSG_KEY_ID 1

#define MSG_SIZE 256

#define MSG_TYPE_JOIN 1
#define MSG_TYPE_CHAT 2
#define MSG_TYPE_LEAVE 3
#define MSG_TYPE_ERROR 4

typedef struct {
	long mtype;				// JOIN, CHAT, LEAVE, ERROR
	pid_t pid;				// needed if mtype == MSG_TYPE_JOIN
	char text[MSG_SIZE];	// text message to send
} msg;

#endif
