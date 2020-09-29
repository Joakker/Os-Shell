#include "utils.h"
#include <string.h>

#define NUM_WORDS   16
#define SEPARATORS  " \t\r\n\a"
char** splitLine(char* line) {
    char** cmd = (char**) malloc(NUM_WORDS * sizeof(char*));
    size_t max = NUM_WORDS;
    size_t pos = 0;

    cmd[pos++] = strtok(line, SEPARATORS);
    while ((cmd[pos++] = strtok(NULL, SEPARATORS)) != NULL) {
        if (pos == max - 1) {
            max += NUM_WORDS;
            cmd = (char**) realloc(cmd, max * sizeof(char*));
        }
    }

    return cmd;
}

