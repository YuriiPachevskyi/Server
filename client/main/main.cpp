#include "Client.h"

int main() {
    Client *client = new Client();
    client->run();
    delete client;

    return 0;
}
