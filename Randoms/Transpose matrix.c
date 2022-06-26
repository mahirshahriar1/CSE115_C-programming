#include<stdio.h>

int main()
{
    int row,col;

    printf("Enter the number of row: ");
    scanf("%d", &row);

    printf("Enter the number of column: ");
    scanf("%d", &col);

    int mat[row][col];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("Element-[%d][%d]: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    int trans[col][row];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            trans[j][i]=mat[i][j];

        }
    }
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            printf("%3d ",trans[i][j]);
        }
        printf("\n");
    }






    return 0;
}
