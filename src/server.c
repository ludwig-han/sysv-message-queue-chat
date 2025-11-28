#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>
#include "ipc.h"
#include "util.h"

int main()
{
    msg msg_out[MAX_USER];      // Queue array for broadcast
    int user_index = 0;         // number of users - 1

	// For Receiving msg from Client
	key_t key_in;
	msg msg_in;


	// For Sending Msg to Each Client
	key_t key_out1, key_out2, key_out3;


	// <=========== Create MSG Queue for Receive Msgs from Client ============>
	key_in = ftok(MSG_KEY_PATH, MSG_KEY_ID);
	if (key_in == -1) {
		perror("ftok failed");
		exit(1);
	}

	int id_in = msgget(key_in, IPC_CREAT | 0644);
	if (id_in == -1) {
		perror("msgget failed");
		exit(1);
	}

	// <============ Start Listening to Client =============>
	while (1) {

		receive_message(id_in, &msg_in);
		
		switch (msg_in.mtype) {
			case MSG_TYPE_JOIN:
				printf("Received msg\tmtype: %ld\tpid: %d\n", msg_in.mtype, msg_in.pid);
//                if (user_index >= MAX_USER) {
                    printf("Error: Too many users!\n");
                    msg_in.mtype = MSG_TYPE_ERROR;
                    strcpy(msg_in.text, "Error: Too many users!");
                    send_message(id_in, &msg_in);
//                }

				break;

			case MSG_TYPE_CHAT:
				break;

			default:
				printf("Error: Unknown Message Type\n");
		}
	}

	return 0;
}
