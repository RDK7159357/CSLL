/* PROGRAM: four.c - Simulating 'ls' command
 * PURPOSE: List files and directories in a specified directory
 * USAGE: ./four
 * Then enter directory name when prompted
 * OUTPUT: inode_number filename (for each entry in directory)
 */

#include <dirent.h>  /* for DIR, struct dirent, opendir(), readdir(), closedir() */
#include <stdio.h>   /* for printf(), scanf(), fflush() */

int main(){
    /* Variable declarations:
     * d[256] = buffer to store directory name
     * dp = DIR pointer (directory stream handle)
     * e = pointer to struct dirent (directory entry structure)
     *     dirent contains: d_ino (inode number), d_name (filename string)
     */
    char d[256];
    DIR *dp;
    struct dirent *e;

    /* Prompt user for directory name and flush stdout */
    printf("directory: ");
    fflush(stdout);

    /* Read directory name from stdin */
    if(scanf("%255s", d) != 1) return 1;  /* exit if read fails */

    /* Open directory for reading
     * opendir() returns DIR pointer on success, NULL on failure
     * The directory stream allows iteration through entries
     */
    if(!(dp = opendir(d))) return 1;  /* exit if opendir fails */

    /* Read directory entries one by one:
     * readdir() returns pointer to next dirent structure
     * NULL is returned when there are no more entries (end of directory)
     * For each entry, print: inode_number (d_ino) and filename (d_name)
     */
    while((e = readdir(dp))) {
        /* Print inode number (cast to unsigned long for portability)
         * and filename separated by space and newline
         */
        printf("%lu %s\n", (unsigned long)e->d_ino, e->d_name);
    }
    /* Note: closedir() is not called for brevity, but should be done in production code */
}
