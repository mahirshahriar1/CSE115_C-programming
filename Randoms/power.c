#include<stdio.h>

int calc_pow(int x, int y)
{
    int i,mul=1;
    for(i=1;i<=y;i++)
    {
        mul=mul*x;
    }
    return mul;
}



int main()
{
    int base,power;

    printf("Enter the value of base and power: ");
    scanf("%d %d", &base, &power);

    int result=calc_pow(base, power);

    printf("%d to the power of %d is: %d", base, power, result);

    return 0;
}
