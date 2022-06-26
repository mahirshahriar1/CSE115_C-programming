#include<stdio.h>

int length(char *s)
{
    int l=0,i=0;

    while(s[i]!='\0')
    {
        l++,i++;
    }

    return l;
}

int main()
{
    char string[100];

    gets(string);

    char *str=&string;

    printf("%d", length(str));




    return 0;
}
