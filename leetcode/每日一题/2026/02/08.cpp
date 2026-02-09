//https://leetcode.cn/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ok = true;
    int dfs(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!ok){
            return 0;
        }
        int s = 1;
        int left = 0;
        int right = 0;

        if(root->left){
            left = dfs(root->left);
        }

        if(root->right){
            right = dfs(root->right);
        }
       if(abs(left - right) > 1){
            ok = false;
       }
       return s + max(left,right);
    }

    bool isBalanced(TreeNode* root) {
       dfs(root);
       return ok;
    }
};