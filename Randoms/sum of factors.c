#include <stdio.h>

int sumof(int n)
{
    int sum=0;
     printf("The factors of %d:",n);
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
           printf("%d ", i);
           sum=sum+i;
        }

    }
    return sum;
}

int main()
{
    int num,summation=0;

    while(1)
    {
        printf("Enter number:");
        scanf("%d", &num);
        if(num==0)
        {
            printf("\n");
            continue;
        }

        else if(num<0)
            break;

        summation=summation+sumof(num);
        printf("\n");

    }
    printf("The sum of factor's sum is %d\nDone with Mid Term. ", summation);


    return 0;
}
