#include <stdio.h>

int main()
{
    printf("Enter array size: ");
    int n;
    scanf("%d", &n);

    int arr[n],temp;
     for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

     for(int i=0;i<3;i++)
    {
        int j, last;

        last=arr[n-1];

        for(j=n-1; j > 0; j--)
        {
              arr[j] = arr[j-1];
        }

        arr[0] = last;
    }

    printf("\n");

    printf("Array after shifting: \n");
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
