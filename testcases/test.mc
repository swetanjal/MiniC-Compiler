int main()
{
    int N, M, a, b, c;
    a = 3;
    M = a + 4;
    N = a + 4;
    a = M + N;
    b = M + N;
    if(a > 0)
    {
        c = a + M;
    }
    else
    {
        c = b + N;
    }
    
    return 0;
}