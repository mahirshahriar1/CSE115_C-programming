// 1/1^1+2/2^2+3/3^3

#include <stdio.h>

int calc_pow(int x, int y)
{
    int i,mul=1;
    for(i=1;i<=y;i++)
    {
        mul=mul*x;
    }
    return mul;
}

double series(int x)
{
    int i;
    double sum=0;
    for(i=1;i<=x;i++)
    {
        sum=sum+(double)i/calc_pow(i,i);
    }
    return sum;
}


int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    printf("sum is %.2lf", series(n));

    return 0;
}
