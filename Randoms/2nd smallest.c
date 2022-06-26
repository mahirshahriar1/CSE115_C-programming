#include <stdio.h>

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int small=arr[0];


    for(int i=0;i<n;i++)
        {
            if(arr[i]<small)
                small=arr[i];
        }
    int small2=999999999;
    for(int i=0;i<n;i++)
        {
            if(arr[i]==small)
                continue;

            if(arr[i]<small2)
                small2=arr[i];
        }
    printf(" %d", small2);

    return 0;
}


