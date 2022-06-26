
#include <stdio.h>

int pell(int n)
{
   if(n == 2)
        return 1;
   else if(n==1)
        return 0;

    else
      return (2*pell(n-1) + pell(n-2));

}

int main()
{
   int n;

   do{
        printf("Enter n: ");
      scanf("%d", &n);
    }while(n<=2);

      for (int i=0; i<n; i++)
    {
        printf("%d  ", pell(i));
    }

    return 0;
}
