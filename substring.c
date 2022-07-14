#include "monty.h"
int substring(char * a, char * b)
{
    int i;

    for (i = 0; b[i]; i++)
    {
        if (b[i] != a[i])
        {
            return 0;
        }
    }
    return 1;
}