#include "ElemSN.h"

int b[5] = {};
// 不统计链接结点的个数，判断链表是否有奇数个结点

ElemSN *IfOddNumNode(ElemSN *h)
{
    ElemSN *p; for (p = h; p && p->next; p = p->next->next);
    return p;
}

ElemSN *CreateLink110(int a[])
{
    ElemSN *h=NULL, *tail, *p;
    for (int i = 0; i < 5; i++)
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

int main()
{
    ElemSN *head;
    head = CreateLink110(b);
    PrintLink(head);
    if (IfOddNumNode(head))
        printf("even\n");
    else
        printf("odd\n");

    return 0;
}
