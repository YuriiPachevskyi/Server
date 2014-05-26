#ifndef WORKER_H
#define WORKER_H

#include "Listener.h"

class Worker: public Listener {
	private:
		int id;
		static int counter; 
	public:
		Worker(int port);
		void run();
		void initWorker();
		void setForWork();
		~Worker();
};

#endif //WORKER_H