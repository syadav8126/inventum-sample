#include <stdio.h>/**
 * main - print locations of Command line arguments and environment
 * variables.
 *
 * Return: 0 every time.
 */
int main(int argc, char *argv[], char **env)
{
  int i;  printf("Address of the array of arguments: %p\n", (void *)argv);
  printf("Addresses of the arguments:\n");
  for (i = 0; i < argc; i++)
  {
    printf("\t[%s]:%p\n", argv[i], argv[i]);
  }
  printf("Address of the array of environment variables: %p\n", (void *)env);
  printf("Address of the first environment variable: %p\n", (void *)(env[0]));
  while (1)
  {
    sleep(1);
  }
  return (0);
}
