// sum of 1/1!+2/2!+3/3!+........n/n!

#include <stdio.h>

int factorial(int a)
{
    int i,fact=1;
    for(i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    return fact;
}

double series(int x)
{
    int i;
    double sum=0;
    for(i=1;i<=x;i++)
    {
        sum=sum+(double)i/factorial(i);//// ei function bad die just fact=fact*i dileo hoy
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
