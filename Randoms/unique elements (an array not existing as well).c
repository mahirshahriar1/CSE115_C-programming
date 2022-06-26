#include<stdio.h>

int main()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nUnique elements are: ");

    for(int i=0;i<n;i++)
    {
        int ctr=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j])
                ctr++;
            }
        }
        if(ctr==0)
        {
            printf("%d ", arr[i]);
        }
    }

    /*int store, a=0;

    while(1)
    {
         for(int j=0;j<n;j++)
        {
            if(arr[j]==a)
            {
                a++;
                continue;
            }

        }
        break;
    }
    printf("%d", a);*/
 //element not present in an array eta diye basically array te boshaye ekta jinish kora jaite pare




    return 0;
}
