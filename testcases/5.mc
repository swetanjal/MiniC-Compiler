int A[10];
int N;
void permute(int l, int r)  
{  
    int i;
    if (l == r)
    {
        for(i = 0; i < N; i = i + 1)
        {
            print(A[i] + " ");
        }
        println("");
    } 
    else
    {  
        for (i = l; i <= r; i = i + 1)  
        {  
            int tmp;
            tmp = A[l];
            A[l] = A[i];
            A[i] = tmp;  
            permute(l + 1, r);  
            tmp = A[l];
            A[l] = A[i];
            A[i] = tmp;  
        }
    }  
}

int main()  
{  
    int i;
    N = read_int();
    for(i = 0; i < N; i = i + 1)
    {
        A[i] = i + 1;
    }
    permute(0, N - 1);  
    return 0;  
}  