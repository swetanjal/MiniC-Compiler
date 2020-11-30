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
        print(N);
        println(" is a prime number");
    }
    else{
        print(N);
        println(" is not a prime number.");
    }
    return 0;
}