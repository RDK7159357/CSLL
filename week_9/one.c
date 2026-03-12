/* PROGRAM: one.c - Simulating 'cat' command
 * PURPOSE: Read a file and display its contents to stdout
 * USAGE: ./one
 * Then enter the filename when prompted
 */

#include <unistd.h>  /* for read(), write() functions */
#include <fcntl.h>   /* for open() and O_RDONLY flag */
#include <stdio.h>   /* for printf(), scanf(), fflush() */

int main(){
    /* Variable declarations:
     * f[256] = buffer to store filename
     * c = character buffer to read one byte at a time
     * fd = file descriptor returned by open()
     * n = return value from read() (number of bytes read)
     */
    char f[256], c;
    int fd;
    ssize_t n;

    /* Prompt user for filename and flush stdout to ensure display */
    printf("filename: ");
    fflush(stdout);

    /* Read filename from stdin (max 255 chars + null terminator) */
    if(scanf("%255s", f) != 1) return 1;  /* exit if read fails */

    /* Open file in read-only mode. Return error if open fails */
    if((fd = open(f, O_RDONLY)) < 0) return 1;

    /* Read file character-by-character and write to stdout:
     * read() returns bytes read (>0 means success, 0 means EOF, <0 means error)
     * write() outputs each character to fd 1 (stdout)
     */
    while((n = read(fd, &c, 1)) > 0)
        write(1, &c, 1);  /* fd 1 = stdout */
}
 
