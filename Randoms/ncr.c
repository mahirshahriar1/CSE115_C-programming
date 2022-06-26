//nCr= n!/r!(n-r)! ..... nCr=n!*(n-r)!

int factorial(int x)
{
    int fact=1;

    for(int i=1; i<=x;i++)

    {
        fact=fact*i;
    }

    return fact;
}

int main()
{
    int n,r, nCr;

    printf("Enter the value of n and r: ");
    scanf("%d %d", &n, &r);

    nCr=factorial(n)/(factorial(r)*factorial(n-r));

    printf("%dC%d is %d", n,r, nCr);

    return 0;
}
