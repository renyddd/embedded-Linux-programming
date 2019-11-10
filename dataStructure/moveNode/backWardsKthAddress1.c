#include "ElemSN.h"

ElemSN *BackWardsCount(ElemSN *h, int k)
{
    ElemSN *pend = NULL, *p;
    int cnt = 0;
    while (pend - h && cnt < k) {
        for (p = h; p->next - pend; p = p->next)
            ;
        cnt ++;
        pend = p;
    }
    if (cnt < k)
        return NULL;
    else
        return pend;
}

int main()
{
    ElemSN *head, *pkey;
    head = CreateHLink(a, N);
    PrintHLink(head);
    pkey = BackWardsCount(head, 4);
    if (!pkey)
    {
    perror("Num is too large");
        exit(1);
    }
    printf("the data of pkey is: %d", pkey->data);
    printf("\n");
    printf("pkey is: %p", pkey);
    printf("\n");

    return 0;
}
