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

    printf("max= %d", small);

    return 0;
}

