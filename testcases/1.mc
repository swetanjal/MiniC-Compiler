int N, k;

int main()
{
    int i, j, s;
    N = read_int();
    k = read_int();
    s = 0;
    for(i = 1; i <= N; i = i + 1)
    {
        int tmp;
        tmp = 1;
        for(j = 1; j <= k; j = j + 1)
        {
            tmp = tmp * i; 
        }
        s = s + tmp;
    }
    print(s);
    return 0;
}