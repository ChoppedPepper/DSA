#include <stack>
#include "TreeNode.hpp"

void goAlongLeft(TreeNode* node, stack<TreeNode*>& sta){
    while(node){
        sta.push(node);
        node = node->left;
    }
    return;
}

void traverseIn(TreeNode* pRoot)
    {
        if(!pRoot) return;

        stack<TreeNode*> sta; // 不必初始化
        while(1){
            goAlongLeft(pRoot, sta);
            if(sta.empty()) break;
            pRoot = sta.top();
            sta.pop();

            // do your work
            
            pRoot = pRoot->right;
        }
        return;
    }