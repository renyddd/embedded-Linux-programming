#include "ElemSN.h"

ElemSN *BackWardsCount(ElemSN *h, int k)
{
    ElemSN *p1, *p2;
    int i = 0;
    for (p1 = h; p1 && i < k; p1 = p1->next, i++)
        ;
    if (!p1)
        return NULL;
    else
    {
        for (p2 = h; p1; p1 = p1->next, p2 = p2->next)
            ;
        return p2;
    }
}
// 隔着跳，p1 开始时让 p2 k 个结点
// 之后，p2 就比 p1 晚到 k 个结点，即倒数第 k 个结点

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
