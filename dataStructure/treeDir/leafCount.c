#include "BTNode.h"

int LeafCount(BTNode *root)
{
    int leafCnt;
    if (!root)
        leafCnt = 0;
    else if (!root->left && !root->right)
        leafCnt = 1;
    else
        leafCnt = LeafCount(root->left) + LeafCount(root->right);

    return leafCnt;
}


int main()
{
    BTNode *root;
    root = CreateBTree(Data, 9);

    printf("前序遍历 ");
    FOrder(root);
    printf("\n");

    printf("the num of the leaf is: %d", LeafCount(root));
    printf("\n");
    return 0;
}
