#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int main() {

switch (fork())
{
case 0:
    pid_t p = getpgrp();
    setpgid(getpid(), 0);
    
    switch (fork())
    {
    case 0:
        fprintf(stdout, "1.1 - %d %d %d\n", getpid(), getppid(), getpgrp());
        break;
    default:
        fprintf(stdout, "1 - %d %d %d\n", getpid(), getppid(), getpgrp());
        //setpgid(getpid(), p);
        break;
    }
    break;

default:

    waitpid(0, NULL, 0);
    perror("");
    fprintf(stdout, "0 - %d %d %d\n", getpid(), getppid(), getpgrp());
    break;
}


}