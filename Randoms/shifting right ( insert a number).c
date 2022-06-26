#include <stdio.h>

int main()
{
   int arr1[100],i,n,ind;

    printf("Input the size of array : ");
    scanf("%d", &n);
       printf("Input %d elements in the array in ascending order:\n",n);
       for(i=0;i<n;i++)
            {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }

   printf("The exist array list is :\n");
   for(i=0;i<n;i++)
      printf("% 5d",arr1[i]);

    printf("\nInput the index to store the value: ");
   scanf("%d",&ind);

   for(i=n;i>ind;i--)
   {
       arr1[i]= arr1[i-1];
   }
   printf("Enter the element to store in index %d: ", ind);
   scanf("%d", &arr1[ind]);


   for(i=0;i<=n;i++)
      printf("% 5d",arr1[i]);
	  printf("\n");
}
