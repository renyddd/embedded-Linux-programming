#include <stdio.h>
#include <stdlib.h>

#define Max 100

int ExchangeBinary(int *s, int x);
int PrintBin(int *s, int top);

int main(int argc, char *argv[])
{
    int *s; //指向栈空间
    int top, x = 11;

    s = (int *)malloc(Max * sizeof(int));
    top = ExchangeBinary(s, x);
    top = PrintBin(s, top);
    free(s);

    return 0;
}

int ExchangeBinary(int *s, int x)
{
    int top = -1;
    while (x) {
        s[++top] = x % 2;
        x /= 2;
    }
    return top;
}

int PrintBin(int *s, int top)
{
    while (top + 1) {
        printf("%5d", s[top--]);
    }
    printf("\n");
    return top;
}
