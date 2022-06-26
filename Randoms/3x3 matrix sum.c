#include<stdio.h>

int main()
{
    int arr[3][3]={{2,1,3},{1,3,7},{7,6,4}};

    printf("3x3 Matrix of ID is:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }


    int sum[3]={0,0,0};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            sum[j]=sum[j]+arr[i][j];// j jokhn 0 column tokhn sum 0 index e sum,, jokhn 1 column tokhn sum 1 index e sum
    }

    for(int i=0;i<3;i++)
        printf("Sum of %dth column is: %d\n", i+1, sum[i]);


    return 0;
}
