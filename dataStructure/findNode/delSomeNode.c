#include "ElemSN.h"

int ab[]={3,2,3,2,4,3,6,9,3,2,0,0,4};

ElemSN *DelSomeNode(ElemSN *h, int key)
{
    ElemSN *p, *q;
    p = h;
    while(p){
        if (p->data - key)
        {
            q = p;
            p = p->next;
        }
        else if (p - h)
        {
            q->next = p->next;
            free(p);
            p = p->next;
        }
        else
        {
            h = h->next;
            free(p);
            p = h;
        }
    }
    return h;
}

int main(int argc, char *argv[])
{
    ElemSN *head;
    int deldata = atoi(argv[1]);

    head = CreateLink1(ab);
    PrintLink(head);
    head = DelSomeNode(head, deldata);
    PrintLink(head);

    return 0;
}
