#include <stdio.h>

typedef struct student{

    int id;
    char name[50];
    float cgpa;

} Student ;


int n;
void writefile(Student *ptr);
void readfile();

int main()
{

   /*do{
        printf("Enter n: ");
      scanf("%d", &n);
    }while(n<1);

    Student s[n];
      for (int i=0; i<n; i++)
    {
        scanf("%d", &s[i].id);
        fflush(stdin);
        fgets(s[i].name, 50, stdin);
        scanf("%f", &s[i].cgpa);
    }
    writefile(s);*/
    readfile();




    return 0;
}
void writefile(Student *ptr)
{
    FILE *test;
    test=fopen("StudentInfo.txt", "a");

    if(test==NULL)
            printf("Error");
    else
    {
        for(int i=0;i<n;i++)
        {
              fprintf(test,"%d %s %f\n", ptr->id, ptr->name,ptr->cgpa);
              ptr++;
        }

    }
    fclose(test);
}

void readfile()
{
    Student p;
    FILE *test;
    test=fopen("StudentInfo.txt", "r");

    if(test==NULL)
            printf("Error");
    else
    {
        fseek(test, sizeof(Student, SEEK_CUR);
        fscanf(test, "%d %s %f", &p.id, p.name, &p.cgpa);
        printf("%d %s %f\n", p.id, p.name, p.cgpa);
         fscanf(test, "%d %s %f", &p.id, p.name, &p.cgpa);
        printf("%d %s %f\n", p.id, p.name, p.cgpa);
    }
    fclose(test);

}


