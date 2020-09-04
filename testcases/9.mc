int A[1000][1000];
int B[1000][1000];
int res[1000][1000];
int main()
{
    int N, M, i, j;
    N = read_int();
    M = read_int();
    for(i = 0; i < N; i = i + 1)
    {
        for(j = 0; j < M; j = j + 1)
        {
            A[i][j] = read_int();
        }
    }

    for(i = 0; i < N; i = i + 1)
    {
        for(j = 0; j < M; j = j + 1)
        {
            B[i][j] = read_int();
            res[i][j] = A[i][j] + B[i][j];
            print(res[i][j] + " ");
        }
        println("");
    }
}