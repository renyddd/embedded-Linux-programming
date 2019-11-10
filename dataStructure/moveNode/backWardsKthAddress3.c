#include "ElemSN.h"

ElemSN *BackWardsCount(ElemSN *h, int k)
{
    ElemSN *p;
    int n = 0, i;
    for (p = h; p; n++, p = p->next)
        ;
    if (n >= k)
        for (p = h, i = 0; i < n - k; p = p->next, i++);

    return p;
}

int main()
{
    ElemSN *head, *pkey;
    head = CreateHLink(a, N);
    PrintHLink(head);
    pkey = BackWardsCount(head, 7);
    if (!pkey)
    {
    perror("the num is too large");
        exit(1);
    }
    printf("the data of pkey is: %d", pkey->data);
    printf("\n");
    printf("pkey is: %p", pkey);
    printf("\n");

    return 0;
}
