#include "ElemSN.h"

ElemSN *FindKeyNode(ElemSN *h, int key)
{
    ElemSN *p = NULL;
    for (p = h; p&&p->data - key; p = p->next);
    return p;
}

int main()
{
    ElemSN *head = NULL, *pkey = NULL;
    head = CreateLink1(a);
    PrintLink(head);

    pkey = FindKeyNode(head, 4);
    printf("the key is: %d\n", pkey->data);

    return 0;
}
