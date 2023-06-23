#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int pwd()
{
    char myPwd[1024];
    if(getcwd(myPwd, 1024) == NULL)
    {
        perror("");
        exit(0);
    }
    printf("%s\n", myPwd);
    return 1;
}