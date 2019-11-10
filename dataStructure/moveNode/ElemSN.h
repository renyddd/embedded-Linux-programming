#include <stdio.h>
#include <stdlib.h>

#define N 10
int a[N] = {3, 2, 5, 8, 4, 7, 6, 9, 1, 10};

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

// 不待表头结点，的链表打印
void PrintLink(ElemSN *h)
{
    ElemSN *p;
    printf("the data is: \t");
    for (p = h; p; p = p->next)
        printf("%d\t", p->data);
}

/*
 _   _                _   _   _           _      
| | | | ___  __ _  __| | | \ | | ___   __| | ___ 
| |_| |/ _ \/ _` |/ _` | |  \| |/ _ \ / _` |/ _ \
|  _  |  __/ (_| | (_| | | |\  | (_) | (_| |  __/
|_| |_|\___|\__,_|\__,_| |_| \_|\___/ \__,_|\___|

*/
                                                 
// 创建带表头结点的链表
ElemSN *CreateHLink(int a[], int n)
{
    ElemSN *h, *t;
    h = t = (ElemSN *)malloc(sizeof(ElemSN));
    h->next = NULL;
    for (int i = 0; i < n; i++)
    {
        t = t->next = (ElemSN *)malloc(sizeof(ElemSN));
        // tail 挂尾链，挪尾指针
        t->data = a[i];
        t->next = NULL;
    }
    return h;
}

// 带表头结点的链表的打印
void PrintHLink(ElemSN *h)
{
    ElemSN *p;
    for (p = h; p->next; p = p->next)
        printf("%d\t", p->next->data);
    printf("\n");
}






