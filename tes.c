#include <stdio.h>
#include <string.h>
int main()
{
    const char *c = strtok("abcd ef", " \t\n");
    printf("%d", strcmp(c, "abcdef"));
    return 1;

}