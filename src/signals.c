#include "signals.h"
#include <signal.h>
#include <stdio.h>

void sigint_handle(int signal) {
    fprintf(stderr, "Interrumpido\n");
}

void setupSignals() {
    signal(SIGINT, sigint_handle);
}
