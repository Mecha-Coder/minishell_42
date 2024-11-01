#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *argv[] = {"cat","in.txt", "out.txt", NULL};
    execve("/usr/bin/cat", argv, NULL);
}
