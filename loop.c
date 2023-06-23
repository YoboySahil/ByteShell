#include "parse.c"
#include "read.c"
#include "execute.c"

void loop()
{
    char *line;
    char **words;
    int status;

    do
    {
        printf("Byteshell_by_sahil>");
        line = read_line();
        // printf("%s", line);
        add_to_hist(line);
        words = split_line(line);
        status = execute(words);
    }while (status);
    
}