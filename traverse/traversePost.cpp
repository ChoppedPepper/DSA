#include <stack>
#include "TreeNode.hpp"

void goToLeftLeaf(stack<TreeNode*>& sta){
    while(sta.top()){
        TreeNode* node = sta.top();
        if(node->left){
            if(node->right){
                sta.push(node->right);
            }
            sta.push(node->left);
        }else{ // 没有左节点就转向右节点，继续循环，直至也没有右节点，向栈中加入一个空节点
            sta.push(node->right)
        }
    }
    sta.pop();
    return;
}

void traversePost(TreeNode* pRoot)
    {
        if(!pRoot) return;

        stack<TreeNode*> sta; 
        sta.push(pRoot); // 初始化
        while(!sta.empty()){
            if(sta.top() != pRoot->parent){ // 判断当前节点是否为上一节点的父节点，若是则直接访问，否则就是右兄
                goToLeftLeaf(sta);
            }
            pRoot = sta.top();
            sta.pop();

            //do your work 
            
        }
        return;
    }