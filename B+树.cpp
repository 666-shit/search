//
// Created by c1533 on 2022/9/25.
//
/**B+树定义：
 * m阶B+树满足以下条件：
 * 1. 每个分支结点最多有m棵子树(孩子结点)
 * 2. 非叶根结点(不是叶子结点的根结点)至少有两棵子树，其他每个分支结点至少有[m/2]棵子树(结点数太少会导致树太高，从而查找效率低)
 * 3. 结点的子树个数与关键字个数相等
 * 4. 所有叶子结点包含全部关键字及指向相应记录的指针，叶结点中将关键字按大小顺序排列，并且相邻叶结点按大小顺序相互连接起来(支持顺序查找)
 * 5. 所有分支结点中仅包含各个子结点中关键字的最大值及指向其子结点的指针(查找到之后，不包含信息，所以还要继续找叶结点)
 *
 * B+树中无论查找是否成功，最后都走到了最下面一层
 * */










