#include <stdio.h>

int main()
{
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    int num[size], temp;

    printf("Please enter %d integers: ", size);

    for(int i=0;i<size;i++)
    {
        scanf("%d", &num[i]);
    }
     printf("\n");
    printf("Before arranging in ascending order: ");
    for(int i=0;i<size;i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("After arranging in ascending order: ");
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1;j++)
       {
           if(num[j]>num[j+1])//arr[0]>arr[1]

        {
            temp=num[j];
            num[j]=num[j+1];
            num[j+1]=temp;
        }

       }
    } ///bubble sort eta arekta nicher ta ami korsi

    /*for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
       {
           if(num[i]>num[j])

        {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
        }

       }
    }
*/


    for(int i=0;i<size;i++)
    {
        printf("%d ", num[i]);
    }


    return 0;
}






