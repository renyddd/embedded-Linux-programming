#include "ElemSN.h"

void DelSingleNode(ElemSN *h, int key)
{
    ElemSN *p, *delp;
    for (p = h; p->next && p->next->data - key; p = p->next)
       ;
    if (!p->next)
        printf("Not Found!\n");
    else
    {
        delp = p->next;
        p->next = delp->next;
        free(delp);
        delp = NULL;
    }
}

int main()
{
    ElemSN *head;
    head = CreateHLink(a, N);
    PrintHLink(head);

    DelSingleNode(head, 3);
    PrintHLink(head);
    return 0;
}
