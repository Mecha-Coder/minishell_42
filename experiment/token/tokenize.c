#include "token.h"

void subtitute_null(char *s, int i, int size)
{
    while(size--)
        s[i++] = '\0';
}

void show_str(char *s, int len)
{
    int i = -1;

    while (++i < len)
    {
        if (s[i] == '\0')   printf("#");
        else                printf("%c", s[i]);
    }
    printf("\n");
}

void show_token(label (*token)[100])
{
    int i;
    label temp; 

    int swap = 1;
    while (swap)
    {
        swap = 0;
        i = 0;
        while ((*token)[i + 1].type >= 0)
        {
            if ((*token)[i].index > (*token)[i + 1].index)
            {
                temp = (*token)[i + 1];
                (*token)[i + 1] = (*token)[i];
                (*token)[i] = temp;
                swap++;
            }
            i++;
        }
    }   

    i = -1;
    printf("\n\n");
    while((*token)[++i].type >= 0)
    {
        if ((*token)[i].type == OR)      printf("%-7s","<OR>");
        else if ((*token)[i].type == PIPE)  printf("%-7s","<PIPE>");
        else if ((*token)[i].type == HERE) printf("%-7s","<HERE>");
        else if ((*token)[i].type == RD)  printf("%-7s","<RD>");
        else if ((*token)[i].type == APPD) printf("%-7s","<APPD>");
        else if ((*token)[i].type == WR)  printf("%-7s","<WR>");
        else if ((*token)[i].type == AND) printf("%-7s","<AND>");
        else if ((*token)[i].type == XAND)  printf("%-7s","<XAND>");
        else if ((*token)[i].type == OB)  printf("%-7s","<OB>");
        else if ((*token)[i].type == CB)  printf("%-7s","<CB>");
        else if ((*token)[i].type == STR)  printf("%-7s","<STR>");

        printf(" %s\n", (*token)[i].content);
    }
    printf("\n\n");
}

void initialize_pattern(char (*pattern)[11][3])
{
    strcpy((*pattern)[OR], "||");
    strcpy((*pattern)[PIPE], "|");
    strcpy((*pattern)[HERE], "<<");
    strcpy((*pattern)[RD], "<");
    strcpy((*pattern)[APPD], ">>");
    strcpy((*pattern)[WR], ">");
    strcpy((*pattern)[AND], "&&");
    strcpy((*pattern)[XAND], "&");
    strcpy((*pattern)[OB], "(");
    strcpy((*pattern)[CB], ")");
    (*pattern)[10][0] = '\0';
}

void tokenize(char *s)
{   
    int i = 0; int j = 0;
    int len = strlen(s);
    label token[100];
    int index;

    char pattern[11][3];
    initialize_pattern(&pattern);

    memset(&token, 0, sizeof(token));

    printf("\n\n%s\n\n", s);

    printf("Stage1: pop operator\n"
            "=====================\n");
    while(j < 100 && pattern[i][0])
    {
        index = find_word(s, len, pattern[i]);
        if (index >= 0)
        {
            token[j++] = (label){i, index, NULL};
            subtitute_null(s, index, strlen(pattern[i]));
        }
        else
            i++;
    }
    show_str(s, len);

    i = -1;
    int state = FALSE;
    printf("Stage2: linked str\n"
            "=====================\n");
    while (j < 100 && ++i < len)
    {
        if (s[i] != ' ' && s[i] != '\0' && state == FALSE)
        {
            token[j++] = (label){STR, i, &s[i]};
            state = TRUE;
        }
        else if (s[i] != ' '&& s[i] != '\0' && state == TRUE)
        {;}
        else
        {
            s[i] = '\0';
            state = FALSE;
        }
    }
    show_str(s, len);
    token[j] = (label){-1, -1, NULL};

    show_token(&token);
}

int main()
{
    char s[] = "<< Hello << EOF cat";
    tokenize(s);
    return (0);
}