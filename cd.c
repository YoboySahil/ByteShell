#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int cd(char **words)
{
    if(words[1] == NULL)
    {
        fprintf(stderr, "Arguments expected a to \"cd\" \n");
    }
    else
    {
        if(chdir(words[1]) != 0)
        {
            perror("ByteShell");
        }
    }
    return 1;
}