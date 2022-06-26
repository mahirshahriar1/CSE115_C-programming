#include<stdio.h>

int main()
{
    char str[200];
    int i,j,count;

    char ch;

    printf("Enter a string : ");
    gets(str);

    int length=0,k=0;
    while(str[k]!=0)
    {
        length++;
        k++;
    }

    int max=0;

    for(i=0; i<length; i++)
    {
        count=1;
        if(str[i])
        {

        for(j=i+1; j<length; j++)
        {
               if(str[i] == str[j])
               {
                    count++;
                    str[j]='\0';

               }
        }
        if(count>max)
            {
                max=count;
                ch=str[i];
            }

        }


    }
       printf("The highest frequency of character '%c' appears number of times:%d", ch, max);

    return 0;
}
