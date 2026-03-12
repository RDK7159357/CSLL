/* PROGRAM: two.c - Simulating 'cp' command
 * PURPOSE: Copy file contents from source to destination
 * USAGE: ./two source_file destination_file
 * Example: ./two file1.txt file2.txt
 */

#include <unistd.h>  /* for read(), write(), open() functions */
#include <fcntl.h>   /* for O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC flags */
#include <stdio.h>   /* for printf(), snprintf() */

int main(int c, char**v) {
    /* Variable declarations:
     * c = argc (argument count)
     * v = argv (argument vector - array of command-line arguments)
     * a[256] = buffer to store source filename
     * b[256] = buffer to store destination filename
     * d = character buffer to store one byte at a time
     * f = file descriptor for source file (opened read-only)
     * g = file descriptor for destination file (opened write/create mode)
     * n = return value from read() (number of bytes read)
     */
    char a[256], b[256], d;
    ssize_t n;

    /* Check if exactly 3 arguments provided (program name + 2 filenames) */
    if(c != 3) {
        printf("usage: %s src dst\n", v[0]);  /* show proper usage message */
        return 1;
    }

    /* Copy command-line arguments into buffers using snprintf */
    snprintf(a, 256, "%s", v[1]);  /* source filename from argv[1] */
    snprintf(b, 256, "%s", v[2]);  /* destination filename from argv[2] */

    /* Open source file in read-only mode (O_RDONLY)
     * Open destination file with write mode and create if not exists
     * O_CREAT = create if not exists
     * O_TRUNC = truncate (clear) if already exists
     * 0644 = file permissions (rw-r--r--)
     */
    int f = open(a, O_RDONLY);
    int g = open(b, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    /* Check if both files opened successfully */
    if(f < 0 || g < 0) return 1;  /* exit if either open fails */

    /* Copy file contents byte-by-byte from source to destination:
     * read(f, &d, 1) = read 1 byte from source file into buffer d
     * write(g, &d, 1) = write 1 byte to destination file from buffer d
     * Loop continues until read returns 0 (end of file)
     */
    while((n = read(f, &d, 1)) > 0)
        write(g, &d, 1);
}

