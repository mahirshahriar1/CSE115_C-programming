#include<stdio.h>

double pi=3.1416;

double Area(double r)
{
    double area;
    area=pi*r*r;

    return area;
}

double diameter(double r)
{
    return 2*r;
}

double circumference(double r)
{
    return 2*pi*r;
}
int main()
{
    double rad,result;

    printf("Enter the value of radius: ");
    scanf("%lf",&rad);


    result=Area(rad);

    printf("Area= %lf\n",result);

    printf("Diameter= %lf\n",diameter(rad));

    printf("Circumference= %lf",circumference(rad));
    return 0;
}
