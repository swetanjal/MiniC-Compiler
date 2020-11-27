#include <stdio.h>
#include <stdbool.h>

int float_to_int(float a)
{
    return (int)a;
}
bool float_to_bool(float a)
{
    return (bool)a;
}
char float_to_char(float a)
{
    return (char)a;
}
int readint()
{
    int a;
    scanf("%d", &a);
    return a;
}

float readfloat()
{
    float a;
    scanf("%f", &a);
    return a;
}

char readchar()
{
    char a;
    scanf("%c", &a);
    return a;
}

bool readbool()
{
    int tmp;
    bool a;
    scanf("%d", &tmp);
    a = (bool)tmp;
    return a;
}

void printint(int a)
{
    printf("%d", a);
}
void printlnint(int a)
{
    printf("%d\n", a);
}
void printbool(int a)
{
    printf("%d", a);
}
void printlnbool(int a)
{
    printf("%d\n", a);
}
void printchar(char a)
{
    printf("%c", a);
}
void printlnchar(char a)
{
    printf("%c\n", a);
}
void printfloat(float a)
{
    printf("%f", a);
}
void printlnfloat(float a)
{
    printf("%f\n", a);
}