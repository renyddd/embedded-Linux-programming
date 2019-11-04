# 数据结构
## 链表
### 链表头文件
ElemSN.h 文件内容如下所示：
```C
#include <stdio.h>
#include <stdlib.h>

#define N 8
int a[N] = {3, 2, 5, 8, 4, 7, 6, 9,};

typedef struct node{
    int data;
    struct node *next;
}ElemSN;

ElemSN *CreateLink1(int a[])
{
    ElemSN *h=NULL, *tail, *p;
    for (int i = 0; i < N; i++)
    {
        p = (ElemSN *)malloc(sizeof(ElemSN));

        if (!h)
            h = tail = p;
        else
            tail = tail->next = p;

        p->data = a[i];
        p->next = NULL;
    }
    return h;
}

void PrintLink(ElemSN *h)
{
    ElemSN *p;
    printf("the data is: \t");
    for (p = h; p; p = p->next)
        printf("%d\t", p->data);
}
```
### 链表基础部分
#### 创建链表 createLink1:
```C
/*
ElemSN *CreateLink1(int a[])
{
    ElemSN *h, *tail, *p;
    h = tail = (ElemSN *)malloc(sizeof(ElemSN));
    h->data = a[0];
    h->next = NULL;
    for (int i = 1; i < N; i++)
    {
        p = (ElemSN *)malloc(sizeof(ElemSN));
        p->data = a[i];
        p->next = NULL;
        tail = tail->next = p;
    }
    return h;
}
*/
ElemSN *CreateLink1(int a[])
{
    ElemSN *h=NULL, *tail, *p;
    for (int i = 0; i < N; i++)
    {
        p = (ElemSN *)malloc(sizeof(ElemSN));

        if (!h)
            h = tail = p;
        else
            tail = tail->next = p;

        p->data = a[i];
        p->next = NULL;
    }
    return h;
}

void PrintLink(ElemSN *h)
{
    ElemSN *p;
    for (p = h; p; p = p->next)
        printf("%d\t", p->data);
}

int main()
{
    int a[N] = {3,2,5,8,4,7};
    ElemSN *head = NULL;
    head = CreateLink1(a);
    PrintLink(head);

    return 0;
}
```
####    逆序输出链表
```C
#include "ElemSN.h"

void InversePrint(ElemSN *h)
{
    ElemSN *p = NULL, *pend = NULL;

    while(pend - h)
    {
        for ( p = h; p->next - pend; p = p->next);
        printf("%d\t", p->data);
        pend = p;
    }
}

int main()
{
    ElemSN *head = NULL;

    head = CreateLink1(a);
    PrintLink(head);
    InversePrint(head);

    return 0;
}
```
## 后记
以后有机会了，再补上代码说明








