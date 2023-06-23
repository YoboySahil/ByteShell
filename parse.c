#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_line(char *line)
{
    int buffer_size = 1024, position = 0;
    char **tokens = malloc(buffer_size * sizeof(char*));
    char *token = strtok(line, " ");
    if(!tokens)
    {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    while(token != NULL)
    {
        // printf("%s\n", token);
        tokens[position] = token;
        position++;
        if(position >= buffer_size)
        {
            buffer_size += buffer_size;
            tokens = realloc(tokens, buffer_size * sizeof(char *));
            if(!tokens)
            {
                fprintf(stderr, "Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " ");
    }
    tokens[position] = NULL;
    return tokens;
}