#include<stdio.h>

void removecons(char arr[], int n);

int main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
     char arr[n];
     for(int i=0;i<n;i++)
    {
        scanf(" %c",&arr[i]);
    }

    removecons(arr,n);


    return 0;
}

void removecons(char A[], int x)
{
    for(int i=0;i<x;i++)
    {

        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u')
            continue;

        for(int j=i;j<x-1;j++)
            {
                A[j]=A[j+1];
            }
            x--,i--;

    }

    for(int i=0;i<x;i++)
         printf("%c,", A[i]);

         printf("\b ");


}
