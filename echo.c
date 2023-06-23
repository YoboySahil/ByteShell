#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int echo(char **words)
{
    int i = 0;
    while(words[i]!=NULL)
    {
        if(i!=0)
            printf("%s ",words[i]);
        i++;
    }
    printf("\n");
    return 1;
}