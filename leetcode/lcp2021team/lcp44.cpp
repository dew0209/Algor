#include <iostream>
#include <vector>
#include <cstring>
/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool st[1010];
class Solution {
public:
    int numColor(TreeNode* root) {
        memset(st,0,sizeof st);
        dfs(root);
        int res = 0;
        for(int i = 1;i <= 1000;i++)if(st[i])res++;
        return res;
    }
    void dfs(TreeNode* node){
        st[node->val] = true;
        if(node->left != nullptr)dfs(node->left);
        if(node->right != nullptr)dfs(node->right);
    }
};