#include "cli.h"
#include "config.h"
#include <sys/wait.h>
#include <unistd.h>

char* getCommandLine() {
    char* line = (char*) malloc(LINE_LENGTH * sizeof(char));
    printf(PS1);
    scanf("%[^\n]", line);
    getc(stdin);
    return line;
}

void launchProgram(char** cmd) {
    int pid = fork();
    if (pid < 0) {
        // Fork falló
        fprintf(stderr, "Fallo al intentar llamar a fork()");
    } else if (pid == 0) {
        // Proceso hijo
        execvp(cmd[0], cmd);
        fprintf(stderr, "%s: Comando no encontrado\n", cmd[0]);
    } else {
        // Proceso padre
        wait(NULL);
    }
    return;
}
