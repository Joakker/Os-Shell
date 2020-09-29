#include "config.h"
#include "cli.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    while (true) {
        char* line = getCommandLine();

        // El usuario emitió un EOF por teclado
        if (feof(stdin))
            break;

        char** cmd = splitLine(line);
        launchProgram(cmd);

        free(line);
        free(cmd);
    }
    return 0;
}
