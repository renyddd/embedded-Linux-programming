// mianshizhunbei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <stdlib.h>
#define N 10


typedef struct node {
    int data;
    struct node* next;
}ElemSN;

ElemSN* CreateLink1(int a[])
{
    ElemSN* h = NULL, * tail = NULL, * p = NULL;
    for (int i = 0; i < N; i++) {
        p = (ElemSN*)malloc(sizeof(ElemSN));
        if (!h)
            h = tail = p;
        else
            tail = tail->next = p;
        p->data = a[i];
        p->next = NULL;
    }
    return h;
}

void PrintLink(ElemSN* h)
{
    ElemSN* p;
    printf("the data is: ");
    for (p = h; p; p = p->next)
        printf("%d, ", p->data);
    printf("\n");
}

void InversePrint(ElemSN* h)
{
    ElemSN* p = NULL, * pend = NULL;
    printf("the inverse data is: ");
    while (pend - h) {
        for (p = h; p->next - pend; p = p->next);
        printf("%d, ", p->data);
        pend = p;
    }
    printf("\n");
}

// 尝试着自己完成一下链表排序
// 记得处理头节点的问题，
ElemSN* sortLink(ElemSN* h)
{
    ElemSN* p, * newh = NULL, * pmin;
    int min, lastmin;

    for (p = h, pmin = h; p; p = p->next) {
        if (p->data < pmin->data) {
            pmin = p;
        }
    }

    min = pmin->data;
    lastmin = min;
    printf("->>>%d\n ", lastmin);

    for (p = h, pmin = h; p; p = p->next) {
        if (p->data < pmin->data && p->data >= lastmin) {
            pmin = p;
        }
        min = pmin->data;
        lastmin = min;
        printf("<%d, ", lastmin);
    }
    return newh;
}

ElemSN* sortLink_backup(ElemSN* h)
{
    ElemSN* p, * pmin, * newh, * pend = NULL, * j;
    // 先创建一个代表头节点的空链表
    newh = (ElemSN*)malloc(sizeof(ElemSN));
    // newh->next 为第一个元素
    newh->next = NULL;
    newh->data = -1;
    // 跳出一个最小后，还需要剔除它
    for (p = h; p; p = p->next) {
        pmin = h;
        for (j = h; j; j = j->next) {
            if (pmin->data > j->data) {
                pmin = j;
            }
        }
        if (pmin == h) {
            h = h->next;
        }
        // add to the link.
        j = (ElemSN*)malloc(sizeof(ElemSN));
        if (newh->next == NULL) {
            j->next = NULL;
        }
        else
            j->next = newh->next;
        newh->next = j;
        j->data = pmin->data;
    }

    return newh;
}

int main()
{
    int a[N] = { 3,2,5,8,4,7,6,9,1,0 };
    ElemSN* head, * newhead;
    head = CreateLink1(a);

    PrintLink(head);
    
    newhead = sortLink(head);
    PrintLink(newhead);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
