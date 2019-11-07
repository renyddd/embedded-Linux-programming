// 假设已有数组 a[]， 通过数组 a 中的元素逆向创建一个链表

#include "ElemSN.h"

ElemSN *PreCreateLink(int a[])
{
    ElemSN *newp, *h = NULL;
    int i;

    for (i = N -1; i >= 0; i--)
    {
        newp = (ElemSN *)malloc(sizeof(ElemSN));
        newp->data = a[i];
        newp->next = h; // 挂链
        h = newp; // 挪 h 指针
        // 最先的结点的 next 指向 NULL，并且 h 指向该结点
        // 接下来，不断的将新创建的结点挂起来，并且挪动 h 指针
    }
    return h;
}

int main()
{
    ElemSN *head;
    head = PreCreateLink(a);
    PrintLink(head);

    return 0;
}
