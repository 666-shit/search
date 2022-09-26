//
// Created by c1533 on 2022/9/18.
//
/**二叉排序树
 * 又称二叉查找树BST
 * 二叉树或空二叉树或具有如下性质的二叉树：
 * 左子树上所有结点的关键字均小于根节点关键字；
 * 右子树上所有结点的关键字均大于根节点的关键字
 * 左子树和右子树各是一棵二叉排序树
 *
 * 即左子树结点值<根节点值<右子树结点值
 * 即进行中序遍历可以得到递增的有序序列
 * */
#include <cstdlib>

/**算法思想
 * 若树非空，目标值与根节点值比较
 * 若相等，则查找成功
 * 若小于，则在左子树上查找，否则在右子树
 * 查找成功，返回结点指针，失败返回nulltpr
 * */
typedef struct BSTNode {
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

BSTNode *BST_Search(BSTree T, int key) {
    while (T != nullptr && key != T->key) {        //树空或等于根节点值，则循环结束
        if (key < T->key) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}   //最坏空间复杂度O(1)

//递归实现
BSTNode *BSTSearch(BSTree T, int key) {
    if (T == nullptr)
        return nullptr;
    if (key == T->key)
        return T;
    else if (key < T->key)
        return BSTSearch(T->lchild, key);
    else
        return BSTSearch(T->rchild, key);
}   //最坏空间复杂度O(h)->树高

//插入
int BST_Insert(BSTree &T, int key) {
    int k = 0;
    if (T == nullptr) {    //原树为空，新插入的结点为根节点
        T = (BSTree) malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = nullptr;
        return 1;           //插入成功
    } else if (k == T->key)   //存在相同结点，插入失败
        return 0;
    else if (k < T->key)
        return BST_Insert(T->lchild, k);     //插到左子树
    else
        return BST_Insert(T->rchild, k);
}

//按照str[]中的关键字序列建立二叉排序树
//str={50,66,60,26,21,30,70,68}
void Create_BST(BSTree &T, int str[], int n) {
    T = nullptr;
    int i = 0;
    while (i < n) {
        BST_Insert(T, str[i]);
        i++;
    }
}

//删除
//若结点z由左右两颗子树，令z的直接后继或前驱代替z，然后从二叉排序树中删除这个直接后继
//z的后继：z的右子树中最左下(中序遍历的第一个结点，该结点一定没有左子树)的结点
//z的前驱：z的左子树中最右下(中序遍历的最后一个结点，该结点一定没有右子树)的结点

/**效率分析：
 * 查找长度——查找中需要对比关键字的次数，反映了查找查找的时间复杂度
 * 平均查找长度ASL=(Σ对比次数(层数)*结点个数)/结点总数
 * 时间复杂度O(h)，平衡二叉树效率最高
 *
 * 查找失败的ASL
 * 比成功多一层，
 * ASL=(3*7+4*2)/9
 * */
