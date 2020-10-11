#include "config.h"
#include "cli.h"
#include "utils.h"
#include "signals.h"
#include "history.h"

#include <unistd.h>
#include <string.h>

void interactiveLoop() {
    setupSignals();
    setupHistory();
    while (true) {
        // Obtiene la línea de comandos del usuario
        char* line = getCommandLine();

        // El usuario emitió un EOF por teclado
        if (feof(stdin))
            break;

        // Añade a la historia
        addToHistory(line);


        // Divide la línea en sus palabras constituyentes
        char** cmd = splitLine(line);
        launchProgram(cmd);

        // Libera los string, ya que ambos fueron
        // alocados dinámicamente
        free(line);
        free(cmd);
    }
    writeHistory();
}

int main(int argc, char* argv[]) {
    int c;
    bool iFlag = false;
    bool cFlag = false;
    char* cArg = NULL;
    bool interactive = true;

    opterr = 0;
    while ((c = getopt(argc, argv, "ic:")) != -1) {
        // Obtiene las banderas de la línea de comandos
        switch (c) {
            case 'i':
                iFlag = true;
                break;
            case 'c':
                if (!iFlag)
                    interactive = false;
                cFlag = true;
                cArg = strdup(optarg);
                break;
        }
    }
    if (cFlag) {
        char** cmd = splitLine(cArg);
        launchProgram(cmd);
        free(cmd);
    }
    if (iFlag || interactive)
        interactiveLoop();
    return 0;
}
