bool isPrime[1000000];
int main()
{
    int N, i, j, sum;
    N = read_int();
    sum = 0;
    for(i = 2 ; i <= N; i = i + 1)
    {
        isPrime[i] = true;
    }
    for(i = 2; i <= N; i = i + 1)
    {
        if(isPrime[i] == true)
        {
            for(j = i + i; j <= N; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(i = 2; i <= N; i = i + 1)
    {
        if(isPrime[i] == true)
        {
            sum = sum + i;
        }
    }
    print(sum);
    return 0;
}