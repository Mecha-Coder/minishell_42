#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

#define IN 0
#define OUT 1

int left(int *fd, int flow, char **env)
{
    pid_t id; 
    char *arg[] = {"ls", NULL};
    int status;

    id = fork();
    if (id < 0) { perror("fork failed"); exit(EXIT_FAILURE);} 
    else if (!id)
    {
        close(fd[!flow]);
        dup2(fd[flow], flow);

        execve("/usr/bin/ls", arg, env);
        perror("execlp ls failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(id, &status,0);
        close(fd[0]);
    }
    return (status);
}

int right(int *fd, int flow, char **env)
{
    pid_t id;
    char *arg[] = {"cat", NULL};
    int status;

    id = fork();
    if (id < 0) {perror("fork failed"); exit(EXIT_FAILURE);}
    else if (!id)
    {
        close(fd[!flow]);
        dup2(fd[flow], flow);

        execve("/usr/bin/cat", arg, env);
        perror("execlp wc failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(id, &status, 0);
        close(fd[1]);
    }
    return (status);
}

int main(int ac, char **av, char **env) //pipe
{
    int fd[2];

    (void)ac;
    (void)av;

    if (pipe(fd) < 0) {perror("pipe failed"); exit(EXIT_FAILURE);}

    left(fd, OUT, env);
    exit_code = right(fd, IN, env);  12

    return 0;
}