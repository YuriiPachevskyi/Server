#ifndef LISTENER_H
#define LISTENER_H

#include "Thread.h"
#include "Includes.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Listener: public Thread {
	private:
    	struct sockaddr_in addr;
    	int listener;
    	int currentPort;
    	// const static int startPort = 3425;

	public:
		Listener();
		void run();
		void initListener();
		void setForListen();
		virtual ~Listener();
};


#endif //LISTENER_H