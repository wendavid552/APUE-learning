#include "apue.h"
#include <sys/wait.h>
int
main(void)
{
    char    buf[MAXLINE];   //MAXLINE the constant comes from apue.h?
    pid_t   pid;
    int     status;
    
    printf("My pid = %d\n",getpid());
    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0;
        
        if((pid = fork()) < 0) {
            err_sys("fork error");
        } else if(pid == 0) {   //'I am my child'
            execlp(buf, buf, (char *)0);    /*To execute the command in buf*/
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
}
