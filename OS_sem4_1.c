// Using pipes, reverse a string, One process takes in the string as input and writes it to a pipe,
// The other processes reads from the pipe and reverse the string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int pipe_fd[2];
    char ip_Srt[200];
    char reversed_Str[200];

    if (pipe(pipe_fd) == -1)
    {
        perror("Pipe creation failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork Failes to create.");
        exit(1);
    }

    if (pid > 0)
    {
        // In Parent process
        close(pipe_fd[0]); // Closeing the read end.
        printf("Enter a string need to be revesed: ");
        fgets(ip_Srt,200,stdin);
        ip_Srt[strlen(ip_Srt)-1] = 0;
        write(pipe_fd[1], ip_Srt, strlen(ip_Srt) + 1); // Writeing to the pipe
        close(pipe_fd[1]);                             // Closeing the pipe
        wait(NULL);
    }
    else
    {
        // In Child process
        close(pipe_fd[1]); // Closeing the Write end.
        read(pipe_fd[0], reversed_Str, sizeof(reversed_Str));
        int len_OrgStr = strlen(reversed_Str); // lenght of the string need to be revesed.
        for (int i = 0; i < len_OrgStr / 2; i++)
        {
            char temp = reversed_Str[i];
            reversed_Str[i] = reversed_Str[len_OrgStr - i - 1];
            reversed_Str[len_OrgStr - i - 1] = temp;
        }
        close(pipe_fd[0]); // Closing the Read end.
        printf("Reversed String: %s\n", reversed_Str);
        exit(0);
    }

    return 0;
}
