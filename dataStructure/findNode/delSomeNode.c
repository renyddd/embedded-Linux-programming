#include <string.h>
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
            p = q->next;
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

    if ( argc < 2 || strcmp(argv[1], "--help") ==0 )
    {
        printf("用法：./a.out [选项]\n");
        exit(1);
    }
    int deldata = atoi(argv[1]);

    head = CreateLink1(ab);
    PrintLink(head);
    head = DelSomeNode(head, deldata);
    PrintLink(head);

    return 0;
}
