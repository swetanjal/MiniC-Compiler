int small[26], caps[26];
int main()
{
    int c, i, idx;
    char EOF;
    EOF = '\0';
    for(i = 0; i < 26; i = i + 1)
    {
        small[i] = 0;
        caps[i] = 0;
    }
    idx = 0;
    while (true) 
    {
       c = fileGetChar("a.txt", idx);
       if(c == EOF)
       {
           break;
       }
       if(c >= 65 && c <= 90)
       {
           caps[c - 65] = caps[c - 65] + 1;
       }
       if(c >= 97 && c <= 122)
       {
           small[c - 97] = small[c - 97] + 1;
       }
       idx = idx + 1;
    }

    for(i = 0; i < 26; i = i + 1)
    {
        char t;
        t = (char)(65 + i);
        print("Number of ");
        print(t);
        print("s is ");
        println(caps[i]);
        t = (char)(97 + i);
        print("Number of ");
        print(t);
        print("s is ");
        println(small[i]);
    }
    return 0;
}