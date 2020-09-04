int main()
{
    int i, j, count;
    count = 0;
    for(i  =  -10000; i <= 10000; i = i + 1)
    {
        for(j = -10000; j <= 10000; j = j + 1)
        {
            int z;
            z = i * i + j * j;
            if(z <= 100000000)
            {
                count = count + 1;
            }
        }
    }
    print(count);
    return 0;
}