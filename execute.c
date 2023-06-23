#include<stdio.h>
#include <stdlib.h>
#include "cd.c"
#include "help.c"
#include "history.c"
#include "exitting.c"
#include "echo.c"
#include "pwd.c"
#include "launch.c"
#include <string.h>

typedef int (*BuiltinFunction)(char**);
BuiltinFunction builtins_functions[] = 
{
        &cd,
        &help,
        &display_history,
        &exitting,
        &echo,
        &pwd
    };

int execute(char **words)
{
    
    char* builtins[] = {"cd", "help","history","exit","echo", "pwd"};
    if(words[0] == NULL)
    {
        return 1;
    }

    int i;
    for(i = 0; i < sizeof(builtins)/sizeof(builtins[0]) ; i++)
    {
        if(strcmp(words[0], builtins[i]) == 0)
        {
            // printf("%d",strcmp(words[0], builtins[i]));
            return (*builtins_functions[i])(words);
        }
    }
    // printf("command not found");
    return launch(words);
}