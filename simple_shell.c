#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define PROMPT "#cisfun$ "
#define BUFFSIZE 1024
/**
 * main - Main Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *argv[2];

    while (1)
    {
        printf(PROMPT);
        fflush(stdout);
        
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        argv[0] = line;
        argv[1] = NULL;

        if (fork() == 0)
        {
            if (execve(line, argv, NULL) == -1)
            {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    free(line);
    return 0;
}
