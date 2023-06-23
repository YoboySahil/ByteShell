#include<stdio.h>
#include <stdlib.h>

char* read_line()
{
    int buffer_size = 1024;
    int position = 0;
    char *buffer = malloc(sizeof(char) *buffer_size);
    int c;

    if(!buffer)
    {
        fprintf(stderr, "Allocation error");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();
        if (c == '\n' )
        {
            buffer[position] = '\0';
            return buffer; 
        }
        else
        {
            buffer[position] = c;
            position++;
        }
        if (position >= buffer_size)
        {
            buffer_size += buffer_size; //doubtful
            buffer = realloc(buffer, buffer_size);
        }
        if (!buffer)
        {
            fprintf(stderr, "allocation error\n");
            exit(EXIT_FAILURE); 
        }
    }
}