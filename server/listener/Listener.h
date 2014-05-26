#ifndef LISTENER_H
#define LISTENER_H

#include "Thread.h"
// #include "Worker.h"
#include "Includes.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Worker;

class Listener: public Thread {
	private:
    	struct sockaddr_in addr;

    protected:
    	int listener;
    	int currentPort;

	public:
		Listener(int port = 3425);
		void run();
		void initListener();
		void setForListen();
		virtual ~Listener();
};


#endif //LISTENER_H