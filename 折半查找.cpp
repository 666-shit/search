//
// Created by c1533 on 2022/9/18.
//
/**折半查找
 * 算法思想：仅适用于有序的顺序表
 * 用两个指针(low, high)指向0和TableLen-1
 * mid指针指向low与high的中间位置，mid=(low+high)/2    除出小数，向下取整
 * 比较被查元素与mid元素大小，确定元素范围，调整low或high指针位置到mid的左侧或右侧一个
 * 重复上述步骤
 * 当被查元素==mid时，查找成功
 * low>high，查找失败
 * */
typedef struct {        //查找表的数据结构(顺序表实现)
    int *elem;      //动态数组基址(malloc申请，elem指针指向)
    int TableLen;   //表的长度
} SSTable;

//折半查找
int Binary_Search(SSTable L, int key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return true;
        else if (L.elem[mid] > key)
            high = mid - 1;     //前半部分继续查找
        else
            low = mid + 1;      //后半部分查找
    }
    return -1;
}
/**效率分析
 * ASL成功：(1*1+2*2+3*4+4*4)/11=3     (11个结点)
 * ASL失败：(3*4+4*8)/12=11/3      (11个成功结点，12个失败结点)
 * 时间复杂度：O(log2_n)
 * */

/**折半查找判定树的构造：
 * 如果当前low和high之间有奇数个元素
 *      则mid分隔后，左右两部分元素个数相等
 * 如果low和high之间有偶数个元素
 *      则mid分隔后，左半部分比右半部分少一个元素
 *      mid=[(low+high)/2]
 *
 * 折半查找的判定树中，若mid=[(low+high)/2]，
 *      则对于任何一个结点，必有：
 *      右子树结点数-左子树结点数=0或1
 * 折半查找的判定树一定是平衡二叉树(左右子树深度之差不超过1)
 * 该树只有最下面一层不满，结点数为n时，树高h=[log2_(n+1)]
 *
 * 判定树结点关键字：左<中<右，满足二叉排序树的定义
 * 失败结点：n+1个，等于成功结点的空链域数量
 * */
