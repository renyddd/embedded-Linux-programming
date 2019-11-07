#include "ElemSN.h"

int ab[] = {1, 1, 2, 3, 4, 5, 6, 6, 7, 8};
// the head will not be deleted.
void DelSameNodeInOrder(ElemSN *h)
{
    ElemSN *p, *q;
    q = h;
    p = h->next;

    while (p){
        if (p->data - q->data)
        {
            q = p;
            p = p->next;
        }
        else 
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
}

int main()
{
    ElemSN *head;
    head = CreateLink1(ab);
    PrintLink(head);
    DelSameNodeInOrder(head);
    PrintLink(head);

    return 0;
}
