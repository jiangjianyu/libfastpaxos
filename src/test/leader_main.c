#include <stdio.h>
#include <unistd.h>
#include "libpaxos.h"

int n_of_acceptors;

int main (int argc, char const *argv[]) {
    int id = 0;
    if (argc > 1)
        n_of_acceptors = atoi(argv[1]);
    else
        return 0;
    if(proposer_init(id, 1) < 0)     {
        printf("leader init failed!\n");
    }
    while(1) {
        sleep(1);
    }
    return 0;
}