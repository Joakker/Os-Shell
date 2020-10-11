#include "cli.h"
#include "config.h"
#include <sys/wait.h>
#include <unistd.h>

char* getCommandLine() {
    char* line = (char*) malloc(LINE_LENGTH * sizeof(char));
    printf("%d", getpid());
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
        printf("\033[0;36m");
        fflush(stdout);
        execvp(cmd[0], cmd);
        fprintf(stderr, "%s: Comando no encontrado\n", cmd[0]);
        exit(0);
    } else {
        // Proceso padre
        wait(NULL);
        printf("\033[0m");
        fflush(stdout);
    }
    return;
}
