#include "BTNode.h"
// 创建一个二叉查找树


int main()
{
    BTNode *root;
    root = CreateBTree(Data, 9);
    int i = 0;
    printf("the data is: ");
    for (; i < 9; i++)
    {
        printf("%5d", Data[i]);
    }
    printf("\n");
    printf("\n");


    printf("前序遍历 ");
    FOrder(root);
    printf("\n");
    printf("中序遍历 ");
    InOrder(root);
    printf("\n");
    printf("后序遍历 ");
    POrder(root);
    printf("\n");

    DestoryBT(root);
    printf("%p", root);
    printf("%d", root->data);
    return 0;
}
