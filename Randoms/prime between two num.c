#include <stdio.h>

int checkPrime(int x)
{
    if(x<=1)
        return 0;

    for (int i=2; i<x; i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}


int main()
{
    int m,n;
    printf("Enter the value of m and n: ");
    scanf("%d %d", &m, &n);

    printf("Prime numbers from %d to %d is: ", m,n);

    for(int i=m; i<=n;i++)
    {

        if(checkPrime(i)==1)
            printf("%d ", i);
    }

    return 0;

}
