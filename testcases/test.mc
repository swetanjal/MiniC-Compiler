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
    int N;
    N = read_int();
    println(fact(N));   
    return 0;
}