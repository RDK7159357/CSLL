#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define DEFAULT_N 10

int main(int argc, char *argv[])
{
    char **tail;
    int count = DEFAULT_N;
    int n, i, tailX = 0, z = 1;
    int lines_read = 0;

    /* 1. Parse Arguments */
    if (argc >= 2) {
        // Check if first arg is a number (e.g., -5)
        if (argv[1][0] == '-' && sscanf(argv[1], "%d", &n) == 1) {
            count = -n; // Convert -5 to 5
            z = 2;      // Filename would be the next argument
        }
        
        // Open file if provided
        if (z < argc) {
            if (freopen(argv[z], "r", stdin) == NULL) {
                fprintf(stderr, "Error: %s not found.\n", argv[z]);
                return 1;
            }
        }
    }

    /* 2. Allocate Memory */
    tail = calloc(count, sizeof(char *));
    for (i = 0; i < count; i++) {
        tail[i] = calloc(MAX_LINE_LEN, sizeof(char));
    }

    /* 3. Fill Circular Buffer */
    // fgets returns NULL on EOF
    while (fgets(tail[tailX], MAX_LINE_LEN, stdin) != NULL) {
        tailX = (tailX + 1) % count;
        lines_read++;
    }

    /* 4. Display Tail */
    /* If we read fewer lines than 'count', start from index 0.
       Otherwise, start from tailX (the oldest line). */
    int start = (lines_read >= count) ? tailX : 0;
    int print_count = (lines_read > count) ? count : lines_read;

    for (i = 0; i < print_count; i++) {
        int index = (start + i) % count;
        printf("%s", tail[index]);
    }

    // Clean up
    for (i = 0; i < count; i++) free(tail[i]);
    free(tail);

    return 0;
}