#include "ElemSN.h"

ElemSN *LastNode(ElemSN *h)
{
    ElemSN *p = NULL;
    for (p = h; p&&p->next; p = p->next);
    return p;
}

int main()
{
    ElemSN *head = NULL, *p = NULL;
    head = CreateLink1(a);
    PrintLink(head);
    
    p = LastNode(head);
    printf("\n the tail node is: %d", p->data);
    return 0;
}
