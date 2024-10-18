#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

//echo   -n   "Hello $USER" ', nice day;)'
//echo "Hello $USER lol " -n "$SHELL"
// echo 'Hi $$'
// echo "[Path $SHELL  '  ' && !]"
//echo "[Path $SHELL$]"
//echo "[Test \'still\' valid $USER]"
//echo "Exit status: $?"
// echo "a"s"f"g"h"
// echo '[Path $SHELL "  " && !]'
// echo '$USER'
// echo 'Hello World'
// echo 'Exit status: $?'
// echo 'a's'f'f'g'h
// echo '$USER'
// echo $USER
// echo $
// echo $HOME$_A55
// echo $~
// Hi "there$USER$?next"
// Hi "there$USER next"
// Hi "there$USERnext"
// echo there$USER$HANTUloo
// echo bonjour > $TEST.txt
// echo "Hello" && echo $?
// echo $$$$#$USER$0
// 'e'"$TRY"'h''o' 'h''i'

void show_str(char **s, char *comment)
{
    int i = 0;
    printf("%s"
            "\n===================\n", comment);
    while(s[i])
        printf("[%s]\n", s[i++]);
    printf("\n\n");
}

void remove_double_quote(char **s)
{
    int i, x;
    int j = -1;
    int detect = 1;

    while(s[++j])
    {
        i = -1;
        while(s[j][++i])
        {
            if (s[j][i] == '\'')
                detect = !detect;
            if (detect && s[j][i] == '\"')
            {
                x = 0;
                while(s[j][i + x])
                {
                    s[j][i + x] = s[j][i + x + 1];
                    x++;
                }
            }
        }
    }
}

int main()
{
    

    char *s[5];
    char s1[] = "echo";
    char s2[] = "-n";
    char s3[] = "\"Hello $USER\"";
    char s4[] = "', nice day;)'";
    s[0] = s1;
    s[1] = s2;
    s[2] = s3;
    s[3] = s4;
    s[4] = NULL;

    show_str(s, "Original");
    remove_double_quote(s);
    show_str(s, "Remove double quote");
}