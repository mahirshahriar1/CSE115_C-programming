#include <stdio.h>

int main()
{

    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n],freq[n];

    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        freq[i]=-1;
    }

    int count;

    for(int i=0; i<n; i++)
    {
        count = 1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                freq[j] = 0;//freq array te -1 initialize but 0 dhukae dibo jokhn duplicate pabo.
            }
        }

        if(freq[i] != 0)
        {
            freq[i] = count;
        }
    }


    for(int i=0; i<n; i++)
    {
        if(freq[i]!=0) //>1 dile duplicate elements ber hoy.. ==1 dile unique elements. !=0 die freq print dile freq
        {
            printf("%d ", freq[i]);
        }
    }



    return 0;
}
