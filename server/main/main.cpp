#include <stdio.h>
#include "Listener.h"
#include "stdio.h"

int main() {
	Listener *vasilii = new Listener();
	vasilii->start();
	vasilii->join();
	// delete vasilii;

	return 0;
}

