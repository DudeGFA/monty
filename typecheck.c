
int digit_check(char key)
{
    int i;

    for(i = 0; i < _strlen(key); i++)
    {
        if(isdigit(key)==0)
        {
            return 0;
        }

    return 1;
}