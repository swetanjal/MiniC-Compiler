int A[1000][1000];
int B[1000][1000];
int res[1000][1000];

int main()
{
    int N1, M1, N2, M2, i, j, k;
    N1 = read_int();
    M1 = read_int();
    N2 = read_int();
    M2 = read_int();

    if(M1 != N2)
    {
        println("Dimensions dont match");
        return 0;
    }
    for(i = 0; i < N1; i = i + 1)
    {
        for(j = 0; j < M1; j = j + 1)
        {
            A[i][j] = read_int();
        }
    }
    for(i = 0; i < N2; i = i + 1)
    {
        for(j = 0; j < M2; j = j + 1)
        {
            B[i][j] = read_int();
        }
    }

    for(i = 0; i < N1; i = i + 1)
    {
        for(j = 0; j < M2; j = j + 1)
        {
            int tmp;
            tmp = 0;
            for(k = 0; k < M1; k = k+1)
            {
                tmp = tmp + (A[i][k] * B[k][j]);
            }
            res[i][j] = tmp;
            print(res[i][j]);
            print(" ");
        }
        println("");
    }
    return 0;
}