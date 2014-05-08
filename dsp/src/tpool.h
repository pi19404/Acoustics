/*
 * tpool.h
 *
 *  Created on: May 5, 2014
 *      Author: root
 */

#ifndef TPOOL_H_
#define TPOOL_H_

#include <iostream>

using namespace std;


#include "logger.h"
#include "_pthread.h"
#include "platform.h"

int shutdown_socket=0;
int sockfd;
struct sockaddr_in server_addr;
pthread_mutex_t accept_lock;
pthread_mutex_t accept_lock1;

char* dataFileName;
typedef struct _IMG_STORE_REQST_TYP {   /* Image Store Request Structure */
    int hydrophone;                 	/* Image Type */
    int number;                 	/* numbers of pages */
} IMG_STORE_REQST_TYP;



void process_message(int new_fd, char *client_ip)
{
while(1)
{
    break;
}
}












#endif /* TPOOL_H_ */
