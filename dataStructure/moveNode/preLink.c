// 设 head 指向一个非空单向链表，将该链表就地逆置
//
#include "ElemSN.h"

ElemSN *PreLink(ElemSN *h)
{
    ElemSN *h1 = NULL, *p;
    while (h){
        p = h;
        h = h->next;
        p->next = h1;
        h1 = p;
    }
    /*
     * 指针 h 向前走
     * 指针 p 在跟随者 h 的同时，不停地将 p->next 指向 h1 链表的尾结点
     * 当 h 走到了最后的 NULL 时，h1 也就走到了 h 的尾结点，即为 h1 的头结点
     */

    return h1;
}

int main()
{
    ElemSN *head, *newHead;
    head = CreateLink1(a);
    PrintLink(head);

    newHead = PreLink(head);
    PrintLink(newHead);

    return 0;
}
