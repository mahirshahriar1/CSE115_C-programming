#include<stdio.h>

int countOddItems(int x[],int z)
{
    int sum=0;
    for(int i=0;i<z;i++)
        sum=sum+x[i];

    double avg=sum/z;
    int count=0;

    for(int i=0;i<z;i++)
    {
        if((x[i]<avg)&&x[i]%2)
            count++;
    }

    return count;
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int r=countOddItems(arr,n);

    printf("Result is: %d", r);




    return 0;
}
