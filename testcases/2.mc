bool isPrime(int s)
{
    int i;
    for(i = 2; i * i <= s; i = i + 1)
    {
        if((s % i) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N;
    bool res;
    N = read_int();
    res = isPrime(N);
    if(res == true)
    {
        println(1);
    }
    else{
        println(0);
    }
    return 0;
}