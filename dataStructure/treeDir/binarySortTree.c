#include "BTNode.h"
// 创建一个二叉查找树

int Data[9] = {6,3,2,7,4,8,5,9,1};
/*
 *              6
 *          3       7
 *      2      4       8
 *   1            5       9
 *
 */
BTNode *CreateBTree(int a[], int n)
{
    BTNode *root, *root_in_while, *each_for_leaf, *process_node;
    int i;
    // 将数组中的第一个元素，作为整棵树的根节点
    root = (BTNode *) malloc (sizeof (BTNode));
    root->data = a[0];
    root->left = root->right = NULL;
    // 
    for (i = 1; i < n; i++)
    {
        process_node = (BTNode *)malloc(sizeof(BTNode));
        process_node->data = a[i];
        process_node->left = process_node->right = NULL;
        // 每一次都从根结点开始遍历，寻找正确的叶子结点
        root_in_while = root;
        // root_in_while 的作用仅为将 each_for_leaf 带往正确的叶子结点上
        while (root_in_while) {
            // 当 root_in_while 为空时，each_for_leaf 便找到了正确的叶子结点
            each_for_leaf = root_in_while;
            if (process_node->data < root_in_while->data)
                root_in_while = root_in_while->left;
            else
                root_in_while = root_in_while->right;
        }

        // 产生新的叶子结点
        if (process_node->data < each_for_leaf->data)
            each_for_leaf->left = process_node;
        else
            each_for_leaf->right = process_node;
    }
    return root;
}

void InOrdor(BTNode *root)
{
    if (root)
    {
        InOrdor(root->left);
        printf("%5d", root->data);
        InOrdor(root->right);
    }
}

int main()
{
    BTNode *root;
    root = CreateBTree(Data, 9);

    InOrdor(root);
    printf("\n");
    return 0;
}
