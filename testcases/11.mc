int main()
{
    FILE fp;
    int c, i, small[26], caps[26];
    fp = fopen("test.txt", "r");
    for(i = 0; i < 26; i = i + 1)
    {
        small[i] = 0;
        caps[i] = 0;
    }
    while (true) 
    {
       c = fgetc(fp);
       if(c >= 65 && c <= 90)
       {
           caps[c - 65] = caps[c - 65] + 1;
       }
       if(c >= 97 && c <= 122)
       {
           small[c - 97] = small[c - 97] + 1;
       }
       if(c == EOF)
       {
           break;
       }
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