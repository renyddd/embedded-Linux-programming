#include "ElemSN.h"

int PrintOddNode(ElemSN *h)
{
    ElemSN *p = NULL;
    int oddCount = 0;
    // 将 oddCount 赋值语句放在自增语句前面，以确保最后一次当 p 为NUll 时，已完成数据域值的判断
    for (p = h; p; oddCount += p->data%2, p = p->next);

    return oddCount;
}

int main()
{
    ElemSN *head = NULL;
    head = CreateLink1(a);

    printf("the count of odd node is: %d\n", PrintOddNode(head));
    return 0;
}
