/*вычисляет длину строки без учета символа null в конце */
int strlen (char line[]) 
{
    int i;
    i=0;

    while((line[i])!='\0')
        ++i;

    return i;
}