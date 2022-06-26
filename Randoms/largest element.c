#include <stdio.h>

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int max=arr[0];


    for(int i=0;i<n;i++)
        {
            if(arr[i]>max)
                max=arr[i];
        }

    printf("max= %d", max);

    return 0;
}
