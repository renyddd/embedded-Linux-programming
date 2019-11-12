#include "BTNode.h"

void showBTNode(BTNode *root)
{
    if (root)
    {
        printf("%d", root->data);
        if (root->left || root->right)
        {
            printf("(");
            showBTNode(root->left);
            if (root->right)
                printf(",");
            showBTNode(root->right);
            printf(")");
        }
    }
}

int main()
{
    BTNode *root;
    root = CreateBTree(Data, 9);

    printf("前序遍历 ");
    FOrder(root);
    printf("\n");

    showBTNode(root);
    printf("\n");
    return 0;
}
