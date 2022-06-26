#include <stdio.h>

int fact(int x)
{
    if(x==0)
        return 1;
    else
        return x*fact(x-1);
}


int main()
{
    int n;
    scanf("%d", &n);

    int r=fact(n);
    printf("Factorial is %d", r);
}
