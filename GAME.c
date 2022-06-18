#include<stdio.h>
#include<stdlib.h>


char arr[5][5]= {{'#',' ',' ','0',' '},{' ',' ','0',' ',' '},{'0',' ',' ',' ','0'},{' ',' ','0',' ',' '},{'0',' ',' ',' ','1'}};
void board();
int check(int a, int b);

int main()
{
    int i=0,j=0;
    char c;


    while(1)
    {
        board();
        printf("\nControls\n--------\nUp   ='w'\nDown ='s'\nLeft ='a'\nRight='d'\n\nObjective\n--------\n*Reach 1 to win. Avoid 0s*\n\n");
        if(check(i,j)==1)
            {
                printf("Game over\n");
                return 0;
            }
        else if(check(i,j)==2)
            {
                printf("Game Win\n");
                return 0;
            }

        printf("Enter movement: ");
        scanf(" %c", &c);


        switch(c)
        {
            case 'd':
                {
                    if(j==4)
                    {
                        printf("Outside range, Game over");
                        return 0;

                    }

                   arr[i][j+1]=arr[i][j];
                   arr[i][j]=' ';
                   j++;
                   break;
                }
            case 'a':
                {
                    if(j==0)
                    {
                        printf("Outside range, Game over");
                        return 0;
                    }

                   arr[i][j-1]=arr[i][j];
                   arr[i][j]=' ';
                   j--;
                   break;
                }
            case 'w':
                {
                    if(i==0)
                    {
                        printf("Outside range, Game over");
                        return 0;
                    }

                   arr[i-1][j]=arr[i][j];
                   arr[i][j]=' ';
                   i--;
                   break;
                }
            case 's':
                {
                    if(i==4)
                    {
                        printf("Outside range, Game over");
                        return 0;
                    }

                   arr[i+1][j]=arr[i][j];
                   arr[i][j]=' ';
                   i++;
                   break;
                }


        }

    }

    return 0;
}


void board()
{
system("cls");
    int i,j;
    printf("\n\n\n");
    for(i=0; i<5; i++)
    { printf("                          ");
    for(j=0; j<5; j++)
        {
            printf("[%c] ",arr[i][j]);
        }
    printf("\n");
    }

}

int check(int a, int b)
{

    if((a==0&&b==3)||(a==1&&b==2)||(a==2&&b==0)||(a==2&&b==4)||(a==3&&b==2)||(a==4&&b==0))
        return 1;

    else if(a==4&&b==4)
          return 2;


    else return 0;
}
