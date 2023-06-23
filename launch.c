#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int launch(char **words)
{
    pid_t pid;
    int status;
    pid = fork();
    if(pid == 0)
    {
        if(execvp(words[0], words) == -1)
        {
            perror("ByteShell");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));   
    }
    return 1;
}