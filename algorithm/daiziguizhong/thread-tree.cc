/**
 * @file thread-tree.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-18
 */



de* cur = root, *pre=NULL, *parent = NULL;

while(cur){
    if(cur->left == NULL){
        if(parent){
            cur->left = parent;
            cur->isLeftThread = true;
        }
        parent = cur;
        cur = cur->right;
    }else{
        pre = cur->left;
        while(pre->right && pre->right != cur){
            pre = pre->right;
        }
        if(pre->right == NULL){
            pre->right = cur;
            pre->isRightThread = true;
            cur = cur->left;
        }else{
            parent = cur;
            cur = cur->right;
        }
    }
}
}
