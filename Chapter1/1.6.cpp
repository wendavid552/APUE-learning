#include "apue.g"
#include <errno.h>

int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCESL %s\n", stderror(EACCES);
    errno = ENORENT;
    perror(argv[0]);
    exit(0);
}
