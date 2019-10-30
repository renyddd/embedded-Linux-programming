#include "ElemSN.h"

ElemSN *MaxNode(ElemSN *h)
{
    ElemSN *p = NULL, *maxp = h;

    for (p = h; p; p = p->next)
        if (maxp->data < p->data)
            maxp = p;

    return maxp;
}

int main()
{
    ElemSN *head = NULL, *pmax = NULL;
    head = CreateLink1(a);
    pmax = MaxNode(head);
    PrintLink(head);
    printf("\nthe max is: %d\n", pmax->data);
    return 0;
}
