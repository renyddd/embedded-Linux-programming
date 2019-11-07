#include <stdio.h>
#include <stdlib.h>

#define N 10
int a[N] = {3, 2, 5, 8, 4, 7, 6, 9,1,10};

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
