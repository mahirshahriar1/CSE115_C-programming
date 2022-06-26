#include<stdio.h>

int sum_number(int x)
{
    if (x==3)   return x;
    else
        return x+sum_number(x-3);
}

int main()
{

    int n;
    scanf("%d", &n);
    printf("%d", sum_number(n));


}
