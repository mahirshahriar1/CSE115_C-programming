
int min(int a, int b, int c)
{
    if(a<=b&&a<=c)// a duitar choto hoile a
        return a;
    else if(b<=c)// a to smallest na so b ar c comparing
        return b;
    else
        return c;
}
