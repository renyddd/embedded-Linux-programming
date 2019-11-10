#include "ElemSN.h"

#define arrayLen 100

ElemSN *BackWardsCount(ElemSN *h, int k)
{
    ElemSN **s, *p;
    int n = 0;

    s = (ElemSN **)malloc(arrayLen * sizeof(ElemSN *));
    for (p = h; p; s[n++] = p, p = p->next)
        ;
    if (n >= k)
        return s[n-k];
    else
        return NULL;
}

int main()
{
    ElemSN *head, *pkey;
    head = CreateHLink(a, N);
    PrintHLink(head);
    pkey = BackWardsCount(head, 4);
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
