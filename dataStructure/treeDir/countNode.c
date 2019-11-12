#include "BTNode.h"

int CountNode(BTNode *root)
{
    if (root)
        return CountNode(root->left) + CountNode(root->right) + 1;
    else
        return 0;
}


int main()
{
    BTNode *root;
    root = CreateBTree(Data, 9);

    printf("前序遍历 ");
    FOrder(root);
    printf("\n");

    printf("the num of the binary is: %d", CountNode(root));
    printf("\n");
    return 0;
}
