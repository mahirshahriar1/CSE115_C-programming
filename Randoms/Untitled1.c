#include<stdio.h>
void capitalize (char *str)
 {
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            if(str[i+1]>='a'&&str[i+1]<='z')

                str[i+1]=str[i+1]-32;
        }

    }
}

int main ()
{
  char arr[100];

  fgets(arr,100,stdin);

  capitalize(arr);
  puts(arr);


  return 0;
}
