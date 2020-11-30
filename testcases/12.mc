char A[100][100];
int cnt, ptr;
int main()
{
    char EOF, c;
    int idx, l, m;
    EOF = '\0';
    cnt = 0;
    idx = 0;
    ptr = 0;
    for(l = 0; l < 100; l = l + 1)
    {
        for(m = 0; m < 100; m = m + 1)
        {
            A[l][m] = '\0';
        }
    }
    while(true)
    {
        c = fileGetChar("a.txt", idx);
        
        if(c == ' ' || c == '\n' || c == EOF)
        {
            int i;
            int found;
            found = 0;
            for(i = 0; i < cnt; i = i + 1)
            {
                int j;
                int match;
                match = 0;
                for(j = 0; true; j = j + 1)
                {
                    if(A[i][j] == A[cnt][j] && A[i][j] == '\0')
                    {
                        match = 1;
                        break;
                    }
                    if(A[i][j] == A[cnt][j])
                    {
                        continue;
                    }
                    break;
                }
                if(match)
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                cnt = cnt + 1;
            }
            ptr = 0;
            if(c == EOF)
            {
                break;
            }
        }
        else
        {
            A[cnt][ptr] = c;
            ptr = ptr + 1;
        }
        idx = idx + 1;
    }
    println(cnt);
    return 0;
}