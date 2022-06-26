#include <stdio.h>

int main()
{
   int arr1[5],i,n,ind;

    printf("Input the size of array : ");
    scanf("%d", &n);

       printf("Input %d elements:\n",n);
       for(i=0;i<n;i++)
            {
	      printf("element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }

   printf("The exist array list is :\n");
   for(i=0;i<n;i++)
      printf("% 5d",arr1[i]);


    do{
        printf("\nInput the index to delete: ");
        scanf("%d",&ind);
    }while(ind<0||ind>n-1);//2

   for(i=ind;i<n-1;i++)
   {
       int temp=arr1[i];
       arr1[i]= arr1[i+1];
        arr1[i+1]=temp;
   }
   n--;//important


   for(i=0;i<n;i++)
      printf("% 5d",arr1[i]);
	  printf("\n");
}

