#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct node{
    int data;
    struct node *next;
}ElemSN;

ElemSN *CreateLink1(int a[])
{
    ElemSN *h = NULL, *tail, *p;

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
