#include "BTNode.h"

int CountDeepth(BTNode *root)
{
    int theDeepth = 0;
    int rightDeepth, leftDeepth;
    if (root)
    {
        leftDeepth = CountDeepth(root->left);
        rightDeepth = CountDeepth(root->right);
        return ((rightDeepth > leftDeepth) ? rightDeepth : leftDeepth + 1);
    }
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

    printf("the deepth is: %d", CountDeepth(root));
    printf("\n");
    return 0;
}
