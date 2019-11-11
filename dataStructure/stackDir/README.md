# 栈 stack
## 1
栈是一种特殊的线性表
- 栈是线性结构
- 栈具有特殊的存储：访问存储、至于栈顶才可被操作、FIFO
- 栈顶（开口），入栈、出栈
- 栈底（封口）

## 2
栈的操作：
- 入栈：向栈中存储元素 push
- 出栈：从栈中取出数据元素 pop
- 栈顶指针 top：用来指向最后一个入栈元素

## 3
入栈操作：
top = top + 1;
s[++top] = 数据值;
设栈的最大方向为 size，则栈满后不可入栈
top == size - 1，上溢

## 4
出栈操作：**只有栈顶元素才可出栈**
栈空不可出栈，下溢
- 栈空条件：top == -1
- 出栈操作：
```c
if (top != -1)
{
    top--;
}
// 出栈元素：s[top+1]
```
## 5
```c

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
```
