#include "ElemSN.h"
 
/*
ElemSN *KAddress(ElemSN *h, int k)
{
    int i;
    ElemSN *p;
    for ( p = h, i = 0; p && i < k; p = p->next, i++)
        ;
    return p;
}
*/

ElemSN *KAddress(ElemSN *h, int k)
{
    int i;
    ElemSN *p;
    for ( p = h, i = 0; p && i - k; p = p->next, i++)
    ;
    // 第零个结点为表头结点
    return p;
}

int main()
{
    ElemSN *head, *KNode = NULL;
    head = CreateHLink(a, N);
    PrintHLink(head);

    KNode = KAddress(head, 0); 
    printf("KData is: %d", KNode->data);
    printf("\n");
    printf("KAddress is: %p", KNode);
    printf("\n");

    return 0;
}
