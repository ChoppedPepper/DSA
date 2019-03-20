#include <stack>
#include "TreeNode.hpp"

void visitAlongLeft(TreeNode* node, stack<TreeNode*>& sta){
    while(node){

        // do your work on node

        sta.push(node->right);
        node = node->left;
    }
    return;
}

void traverseIn(TreeNode* pRoot)
    {
        if(!pRoot) return;

        stack<TreeNode*> sta; // 不必初始化
        while(1){
            visitAlongLeft(pRoot, sta);
            if(sta.empty()) break;
            pRoot = sta.top();
            sta.pop();
        }
        return;
    }