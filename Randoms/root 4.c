#include <stdio.h>
#include <math.h>

double root4(int num);

int main()
{
    int n;
    scanf("%d", &n);

    printf("%.2lf", root4(n));

    return 0;

}

double root4(int num)
{
    double n=num;

    n=sqrt(n);
    n=sqrt(n);

    return n;
}
