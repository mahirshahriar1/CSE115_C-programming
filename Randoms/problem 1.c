#include<stdio.h>
#include<math.h>

int main()
{
    long a,b,c;

    while(scanf("%ld %ld", &a, &b)!=EOF)
    {
        c=abs(b-a);
        printf("%ld\n", c);
    }

    return 0;
}
