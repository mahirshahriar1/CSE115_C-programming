#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the Elements: ");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                 for(int k=j;k<n-1;k++)
                    arr[k]=arr[k+1];
                n--;
                j--;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}
