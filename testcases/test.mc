int fact(int m)
{
    if(m == 0)
    {
        return 1;
    }
    return m * fact(m - 1);
}


int main()
{
    fact(5);   
    return 0;
}