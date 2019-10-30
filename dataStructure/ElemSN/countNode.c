#include "ElemSN.h"

int CountNode(ElemSN *h)
{
    int cnt = 1;
    ElemSN *p;
    for (p = h; p; p = p->next, cnt++);

    return cnt;
}

int main()
{
    ElemSN *head;
    int count = 0;

    head = CreateLink1(a);
    count = CountNode(head);
    printf("count is: %d\n", count);

    return 0;
}
