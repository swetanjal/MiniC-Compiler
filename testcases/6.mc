int A[1000];
int N;
void insertionSort()  
{  
    int i, key, j, n;  
    for (i = 1; i < n; i = i + 1) 
    {  
        key = A[i];  
        j = i - 1;  
        while (j >= 0 && A[j] > key) 
        {  
            A[j + 1] = A[j];  
            j = j - 1;  
        }  
        A[j + 1] = key;  
    }  
}
int main()
{
    int i;
    N = read_int();
    for(i = 0; i < N; i = i + 1)
    {
        A[i] = read_int();
    }
        
    insertionSort();
    for(i = 0; i < N; i = i + 1){
        print(A[i] + " ");
    }
        
    println("");
    return 0;
}