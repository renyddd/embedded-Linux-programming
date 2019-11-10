#include "ElemSN.h"
int ab[N] = {3,2,3,5,7,4,3,8,3,3};

void DelSomeNode(ElemSN *h, int key)
{
    ElemSN *p, *delp;
    for (p = h; p->next;)
    {
        if (p->next->data - key)
            p = p->next;
        else
        {
            delp = p->next;
            p->next = delp->next;
            free(delp);
            delp = NULL;
        }
    }
}

int main()
{
    ElemSN *head;
    head = CreateHLink(ab, N);
    PrintHLink(head);
    DelSomeNode(head, 3);
    PrintHLink(head);

    return 0;
}
