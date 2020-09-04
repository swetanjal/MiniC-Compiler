int A[1000000];

void sort(int l, int r)
{
    int sz, mid, tmp[r - l + 1], l_ptr, r_ptr, c;
    sz = r - l + 1;
    if(sz == 1)
    {
        return;
    }
    mid = (l + r) / 2;
    sort(l, mid);
    sort(mid + 1, r);
    c = 0;
    l_ptr = l; r_ptr = mid + 1;
    while(l_ptr <= mid && r_ptr <= r)
    {
        if(A[l_ptr] < A[r_ptr])
        {
            tmp[c] = A[l_ptr];
            c = c + 1;
            l_ptr = l_ptr + 1;
        }
        else
        {
            tmp[c] = A[r_ptr];
            c = c + 1;
            r_ptr = r_ptr + 1;
        }
    }
    while(l_ptr <= mid)
    {
        tmp[c] = A[l_ptr];
        c = c + 1;
        l_ptr = l_ptr + 1;
    }
    while(r_ptr <= r)
    {
        tmp[c] = A[r_ptr];
        c = c + 1;
        r_ptr = r_ptr + 1;
    }
    for(i = l; i <= r; i = i + 1)
    {
        A[i] = tmp[i - l];
    }
}

int main()
{
    for(i = 0; i < N; i = i + 1){
        A[i] = read_int();
    }
    sort(0, N);    
    for(i = 0; i < N; i = i + 1){
        print(A[i] + " ");
    }
    return 0;
}