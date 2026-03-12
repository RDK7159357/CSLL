/* PROGRAM: three.c - Simulating 'rm' command
 * PURPOSE: Delete multiple files from a specified directory
 * USAGE: ./three
 * Then enter directory name and filenames to delete (Ctrl-D to end)
 */

#include <unistd.h>  /* for chdir() function */
#include <stdio.h>   /* for printf(), scanf(), fflush() */
/* Note: remove() comes from stdlib.h automatically in most systems */

int main(){
    /* Variable declarations:
     * d[256] = buffer to store directory path
     * f[256] = buffer to store filename to delete
     */
    char d[256], f[256];

    /* Prompt user for directory path and flush stdout */
    printf("directory: ");
    fflush(stdout);

    /* Read directory name from stdin */
    if(scanf("%255s", d) != 1) return 1;  /* exit if read fails */

    /* Change working directory to the specified directory
     * This makes all delete operations relative to that directory
     */
    chdir(d);

    /* Infinite loop to accept multiple filenames for deletion */
    while(1) {
        /* Prompt for next filename */
        printf("file: ");
        fflush(stdout);

        /* Read filename from stdin
         * scanf returns 1 if successful, EOF (typically -1) on Ctrl-D
         */
        if(scanf("%255s", f) != 1)
            break;  /* exit loop if no more input (Ctrl-D pressed) */

        /* Delete the file using remove() function
         * remove() deletes the file and returns 0 on success, -1 on error
         */
        remove(f);
    }
}

