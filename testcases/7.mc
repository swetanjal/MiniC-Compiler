int A[1000];
int N;
int getMax() 
{ 
    int mx, i;
    mx = A[0]; 
    for (i = 1; i < n; i = i + 1)
    {
        if (A[i] > mx)
        {
            mx = arr[i];
        }
    }       
    return mx; 
}

void countSort(int exp) 
{ 
    int output[N]; 
    int i, count[10]; 
    
    for(i = 0; i < 10; i = i + 1)
    {
        count[i] = 0;
    } 
    for (i = 0; i < N; i = i + 1) 
    {    
        count[ (A[i]/exp)%10 ] = count[ (A[i]/exp)%10 ] + 1; 
    }
    for (i = 1; i < 10; i = i + 1) 
    {    
        count[i] = count[i] + count[i - 1];
    } 
   
    for (i = N - 1; i >= 0; i = i - 1) 
    { 
        output[count[ (A[i]/exp)%10 ] - 1] = A[i]; 
        count[ (A[i]/exp)%10 ] = count[ (A[i]/exp)%10 ] - 1; 
    } 
    for (i = 0; i < n; i = i + 1) 
    {
        A[i] = output[i];
    } 
}

void radixsort() 
{
    int m, exp;
    m = getMax(); 
    for (exp = 1; (m / exp) > 0; exp = exp * 10)
    {
        countSort(exp);
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
    radixsort();
    for(i = 0; i < N; i = i + 1){
        print(A[i] + " ");
    }
        
    println("");
    return 0;
}