#include <stdio.h>

char str[200], pat[50], rep[50], result[300];

void read();
void match_replace();

int main()
{
    read();
    match_replace();
    return 0;
}

void read()
{
    printf("Enter main string:\n");
    fgets(str, 200, stdin);

    printf("Enter pattern string:\n");
    fgets(pat, 50, stdin);

    printf("Enter replace string:\n");
    fgets(rep, 50, stdin);
}

void match_replace()
{
    int i = 0, j, k = 0, m = 0, n = 0, found = 0;

    while (pat[m] != '\n' && pat[m] != '\0')
        m++;
    while (rep[n] != '\n' && rep[n] != '\0')
        n++;

    while (str[i] != '\0' && str[i] != '\n')
    {
        int match = 1;
        for (j = 0; j < m; j++)
        {
            if (str[i + j] != pat[j])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            found = 1;
            for (j = 0; j < n; j++)
                result[k++] = rep[j];
            i += m;
        }
        else
        {
            result[k++] = str[i++];
        }
    }

    result[k] = '\0';

    if (found)
        printf("Modified string:\n%s", result);
    else
        printf("Pattern not found");
}
