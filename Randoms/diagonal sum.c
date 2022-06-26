#include<stdio.h>
int main()
{
    int n;
    printf("Enter the coloumn & row size:");
    scanf("%d",&n);
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter [%d][%d]:",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Matrix is:\n");
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
    printf("\n");
    }
    int sum=0;
     printf("Diagonal:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                printf("%d",A[i][j]);
                 sum=sum+A[i][j];
            }

            else
            {
                printf(" ");
            }

        }

        printf("\n");
       // sum=sum+A[i][j];
    }
    printf("Sum is %d",sum);
    return 0;
}
