#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include "ipc.h"

#define MAX_USER 10

int send_message(int qid, void *msg);

int receive_message(int qid, void *msg);

void perror_exit(const char *msg);

#endif
