#include<stdio.h>

int main()
{
    char str[200],arr[200];
    int cout[200];
    int i,j,count=0,flag=0;

    printf("Enter a string : ");
    gets(str);

    int length=0,k=0;
    while(str[k]!=0)
    {
        length++;
        k++;
    }
    k=0;
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
        arr[k]=str[i];
        cout[k]=count;
        k++;

        }

    }
    arr[k]='\0';

    for(i=0; arr[i]!='\0'; i++)
    {
        printf("%c %d \n", arr[i], cout[i]);
    }


    return 0;
}
