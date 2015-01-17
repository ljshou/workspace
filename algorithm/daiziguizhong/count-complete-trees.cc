/**
 * @file count-complete-trees.cc
 * @brief count nodes of complete binary tree
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-17
 */

#include <iostream>
using namespace std;

int getHeight(TreeNode root) {
    int res = 0;
    while(!isNullNode(root)) {
        root = getLeftChildNode(root);
        ++ res;
    }
    return res;
}

//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空
// (lgN)^2
int count_complete_binary_tree_nodes(TreeNode root) {
    if(isNullNode(root)) return 0;
    int count = 1;
    int left = getHeight(getLeftChildNode(root));
    int right = getHeight(getRightChildNode(root));

    if(left == right) {
        //左子树满
        count += (1 << left) - 1;
        count += count_complete_binary_tree_nodes(getRightChildNode(root));
    }
    else {
        count += (1 << right) - 1;
        count += count_complete_binary_tree_nodes(getLeftChildNode(root));
    }
    return count;
}
