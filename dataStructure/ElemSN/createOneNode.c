#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}ElemSN;

int main()
{
    ElemSN *p;
    p = (ElemSN *) malloc(sizeof(ElemSN));
    
    p->data = 3;
    p->next = NULL;

    printf("%d\n", p->data);
    return 0;
}
