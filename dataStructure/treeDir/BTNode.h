#include <stdio.h>
#include <stdlib.h>

int Data[9] = {6,3,2,7,4,8,5,9,1};
/*
 *              6
 *          3       7
 *      2      4       8
 *   1            5       9
 *
 */

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} BTNode;

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

// 前序遍历
// 先访根结点，再访左子树，最后访右子树
void FOrder(BTNode *root)
{
    if (root)
    {
        printf("%5d", root->data);
        FOrder(root->left);
        FOrder(root->right);
    }
}

// 中序遍历
void InOrder(BTNode *root)
{
    if (root)
    {
        InOrder(root->left);
        printf("%5d", root->data);
        InOrder(root->right);
    }
}

// 后序遍历
void POrder(BTNode *root)
{
    if (root)
    {
        POrder(root->left);
        POrder(root->right);
        printf("%5d", root->data);
    }
}

// 销毁一颗二叉树
void  DestoryBT(BTNode *root)
{
    if (root)
    {
        DestoryBT(root->left);
        DestoryBT(root->right);
        free(root);
        root = NULL;
    }
}
