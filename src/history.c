#include "history.h"

#include <sys/stat.h>
#include <sys/types.h>

#include <string.h>

size_t historySize = 100;
size_t historyIdx = 0;
char** historyLines;

void setupHistory() {
    historyLines = (char**) malloc(sizeof(char*) * historySize);
}

void addToHistory(char *line) {
    historyLines[historyIdx++] = strdup(line);
    if (historyIdx > (size_t) historySize * 0.75) {
        historySize *= 2;
        historyLines = (char**) realloc(historyLines, historySize);
    }
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
    for (size_t i = 0; i < historyIdx; i++) {
        fprintf(histFile, "%s\n", historyLines[i]);
        free(historyLines[i]);
    }
    free(historyLines);
    fclose(histFile);

    free(cacheDir);
    free(fileName);
}
