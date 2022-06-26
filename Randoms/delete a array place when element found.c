#include <stdio.h>

void removeFromArray(int A[], int N, int V)
{
    for(int i=0;i<N;i++)
    {
        if(A[i]==V)
        {
            for(int j=i;j<N-1;j++)
            {
                A[j]=A[j+1];
            }

            A[N-1]=0;
            break;
        }
    }
    for(int i=0; i<N;i++)
        printf("%d ", A[i]);

}

/*void removeFromArray (int A[], int N, int V)
{
    int flag=0;
    for(int i=0;i<N;i++)
    {
        if(A[i]==V)
        {
            flag++;
        }
        if(flag>=1)
        {
            A[i]=A[i+1];
        }

    }
    A[N-1]=0;
    for(int i=0; i<N;i++)
        printf("%d ", A[i]);
}*/


int main()
{
    int x,n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];


    for(int i=0; i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to remove: ");
    scanf("%d", &x);

    removeFromArray(arr,n,x);

}
