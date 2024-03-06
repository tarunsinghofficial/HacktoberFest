

// 1) Write a programe to create a child process which lists all the executing user processes.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

    pid_t Cprocc;
    Cprocc = fork();

    if (Cprocc < 0)
        printf("Fork Failed.\n");

    else if (Cprocc > 0)
    {
        printf("In Parent-\n");
        printf("Process id = %d\n", getpid());
        int status;
        wait(&status);
    }
    else if (Cprocc == 0)
    {
        printf("In Child-\n");
        printf("Process Id = %d, Parent process id = %d\n", getpid(), getppid());
        execl("/bin/ps", "./ps", NULL);
        // execl("/usr/bin/top","./top",NULL);
        // top monitors the current running processes , where as ps enlists the currnet runnig processes.
    }

    return 0;
}