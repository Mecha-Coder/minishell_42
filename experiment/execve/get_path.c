#include "split.h"

char *get_path(char *check, char **env)
{
    int i;
    char **allpath;
    char *trypath;

    i = -1;
    trypath = join_str(NULL, check);
    if (!access(trypath, F_OK | X_OK))
        return (trypath);
    free(trypath);
    allpath = all_path(env);
    while(allpath && allpath[++i])
    {
        trypath = join_str(allpath[i], check);
        if (!access(trypath, F_OK | X_OK))
            break;
        free(trypath);
        trypath = NULL;
    }
    free_list(allpath);
    return (trypath);
}


void test(char *dest, char **env)
{
	char *s;

	s = get_path(dest, env);
	if (!s)
		printf("String is NULL\n");
	else
	{
		printf("%s\n", s);
		free(s);
	}
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	test("ls", env);
	test("wc", env);
	test("grep", env);
	test("cat", env);
	test("/bin/ls", env);
    test("/usr/bin/ls", env);

    printf("\n\nNULL\n============\n");
    test("urs/bin/ls", env);
    test("bin/ls", env);

    printf("\n\nExecute with relative path\n============\n");

    char *s[] = {"/usr/bin/cat", "split.h", NULL};
    execve("/usr/bin/cat", s, env);
}
