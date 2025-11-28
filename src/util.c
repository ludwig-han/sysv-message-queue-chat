#include "util.h"

int send_message(int qid, void *msg) {
	if (msgsnd(qid, msg, sizeof(msg) - sizeof(long), 0) == -1) {
		perror("msgsnd failed");
		return -1;
	}
	return 0;
}

int receive_message(int qid, void *msg) {
	if (msgrcv(qid, msg, sizeof(msg) - sizeof(long), 0, 0) == -1) {
		perror("msgrv failed");
		return -1;
	}
	return 0;
}

void perror_exit(const char *msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}
