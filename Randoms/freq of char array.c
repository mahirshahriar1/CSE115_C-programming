#include<stdio.h>

int main()
{
    char str[200];
    int i,j,count=0,flag=0;

    printf("Enter a string : ");
    gets(str);

    int length=0,k=0;
    while(str[k]!=0)
    {
        length++;
        k++;
    }

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
          printf("%c = %d \n",str[i],count);

        }



    }

    return 0;
}

/*
    for(i=0; i<strlen(string); i++)
    {

        if(string[i]>='A'&&string[i]<='Z'||string[i]>='a'&&string[i]<='z')
        {
            count=1;
            for(j=i+1; j<strlen(string); j++)
            {
                if(toupper(string[i])==toupper(string[j]))
                {
                    count++;
                    string[j]=' ';
                }
            }

            printf("%c/%c: %d\n",toupper(string[i]),tolower(string[i]),count);
        }


    }*/
