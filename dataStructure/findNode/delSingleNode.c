#include "ElemSN.h"

ElemSN *DelSigleNode(ElemSN *h, int key)
{
    ElemSN *p, *q;
    for (p = h; p&&p->data - key; q = p, p = p->next);
    if (!p)
        printf("Not Found\n");
    else
    {
        if (!(p - h))
        {
            h = h->next;
            free(p);
            p = NULL;
        }
        else
        {
            q->next = p->next;
            free(p);
            p = NULL;
        }
    }
    return h;
}

int main(int argc, char *argv[])
{
    ElemSN *head, *pdel;
    int deldata;
    deldata = atoi(argv[1]);
    // atoi 函数解决将命令行输入的数字转为整数
    head = CreateLink1(a);
    PrintLink(head);

    head = DelSigleNode(head, deldata);
    PrintLink(head);
    return 0;
}
