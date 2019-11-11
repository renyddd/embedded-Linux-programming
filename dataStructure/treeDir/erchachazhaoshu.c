#include "BTNode.h"
// 创建一个二叉查找树

int Data[9] = {6,3,2,7,4,8,5,9,1};
//int Data[9] = {1,3,2,7,4,8,5,9,6};

/*
 *              6
 *          3       7
 *      2      4       8
 *   1            5       9
 *
 */
BTNode *CreateBTree(int a[], int n)
{
    BTNode *root, *c, *pa, *p;
    int i;
    root = (BTNode *) malloc (sizeof (BTNode));
    root->data = a[0];
    root->left = root->right = NULL;
    for (i = 1; i < n; i++)
    {
        p = (BTNode *)malloc(sizeof(BTNode));
        p->data = a[i];
        p->left = p->right = NULL;
        c = root;
        while (c) {
            pa = c;
            if (c->data > p->data)
                c = c->left;
            else
                c = c->right;
        }

        if (pa->data > p->data)
            pa->left = p;
        else
            pa->right = p;
    }
    return root;
}

//  _       __ _     _       _       _          _        _       _     _   
// | | ___ / _| |_  | |   __| | __ _| |_ __ _  | |  _ __(_) __ _| |__ | |_ 
// | |/ _ \ |_| __| | |  / _` |/ _` | __/ _` | | | | '__| |/ _` | '_ \| __|
// | |  __/  _| |_  | | | (_| | (_| | || (_| | | | | |  | | (_| | | | | |_ 
// |_|\___|_|  \__| | |  \__,_|\__,_|\__\__,_| | | |_|  |_|\__, |_| |_|\__|
//                  |_|                        |_|         |___/           


/*
void FOrdor(BTNode *root)
{
    if (root)
    {
        printf("%5d", root->data);
        FOrder(root->left);
        FOrder(root->right);
    }
}
*/

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

/*
（1）若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
（2）若右子树不空，则右子树上所有结点的值均大于它的根结点的值；
（3）左、右子树也分别为二叉排序树；
（4）没有键值相等的结点。
https://baike.baidu.com/item/%E4%BA%8C%E5%8F%89%E6%8E%92%E5%BA%8F%E6%A0%91/10905079?fromtitle=%E4%BA%8C%E5%8F%89%E6%9F%A5%E6%89%BE%E6%A0%91&fromid=7077965&fr=aladdin
 */


