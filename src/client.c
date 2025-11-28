#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "ipc.h"
#include "util.h"

int main()
{
	// for sending message to Server
	int server_in_id;
	key_t server_in_key;
	msg send_msg;

	// for receiving message from Client
	int client_out_id;
	key_t client_out_key;
	msg recv_msg;
	

	// <======== Send Join Message to Server========>
	server_in_key = ftok(MSG_KEY_PATH, MSG_KEY_ID);
	if (server_in_key == -1) {
		perror("ftok failed");
		exit(1);
	}

	server_in_id = msgget(server_in_key, 0);
	if (server_in_id == -1) {
		perror("msgget failed");
		exit(1);
	}

//	strcpy(send_msg.text, "login!");
//	send_message(server_in_id, &send_msg);
    send_msg.mtype = MSG_TYPE_JOIN;
    send_msg.pid = getpid();
    send_message(server_in_id, &send_msg);

	// <========= Receive Response Message From Server ========> 
	receive_message(server_in_id, &recv_msg);
	printf("message from server: %s\n",recv_msg.text);
    printf("error code: %d\n", recv_msg.mtype);

	return 0;
}
