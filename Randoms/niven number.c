#include <stdio.h>

int checkNiven(int num)
{
    int n=num;
    int sum=0;
    while(n!=0)
    {
        sum=sum+n%10;
        n=n/10;
    }
    if(num%sum==0)
        return 1;
    else
        return 0;

}

int main()
{
    int a,b,sum=0;
    scanf("%d %d", &a,&b);

    printf("\nNiven numbers between this range are: ");

    for(int i=a;i<=b;i++)
    {
        if(checkNiven(i)==1)
        {
             printf("%d ", i);
             sum=sum+i;
        }

    }
    printf("\n\nSum of the niven numbers between this range is %d\n", sum);

    return 0;
}
