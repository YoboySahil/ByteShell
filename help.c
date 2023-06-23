#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *builtin_string[] = {
  "cd",
  "help",
  "history",
  "exit",
  "echo",
  "pwd"
};

int help(char **words)
{
  int i;
  printf("ByteShell Project by Sahil\n");
  // printf("Type the name of programs and arguments , and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < sizeof(builtin_string) / sizeof(char *); i++) {
    printf("  %s\n", builtin_string[i]);
  }

  printf("Use thes man line for information on other programs.\n");
  return 1;
}