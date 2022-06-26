#include<stdio.h>

void last(char s[])
{
    int l=strlen(s);
    int j=0;
    char str[l];
    for(int i=l-1;s[i]!='\0';i--)
    {
        if(s[i]==' ')
            break;
        str[j]=s[i];
        j++;
    }
    str[j]='\0';
    int length=strlen(str);
    for(int x=length-1;str[x]!='\0';x--)
    {
        printf("%c", str[x]);
    }

}
int main()
{

   char arr[100];
   gets(arr);

   last(arr);


}

