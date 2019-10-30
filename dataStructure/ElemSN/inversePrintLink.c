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
