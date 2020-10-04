#include "history.h"

#include <sys/stat.h>
#include <sys/types.h>

#include <string.h>

void addToHistory(char *line) {
    ;
}


void writeHistory() {
    char* cacheDir;
    char* fileName;

    cacheDir = getenv("XDG_CACHE_HOME");

    if (cacheDir == NULL) {
        char* home = getenv("HOME");
        char  conf[strlen(home) + 9];
        sprintf(conf, "%s/.config", home);
        cacheDir = strdup(conf);
    } else {
        cacheDir = strdup(cacheDir);
    }

    fileName = malloc(strlen(cacheDir) + 14);

    sprintf(fileName, "%s/posh_history", cacheDir);

    mkdir(cacheDir, 0777);

    FILE* histFile = fopen(fileName, "w");
    fclose(histFile);

    free(cacheDir);
    free(fileName);
}
