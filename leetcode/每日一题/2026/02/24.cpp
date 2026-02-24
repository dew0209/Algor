//https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24


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
    int dfs(TreeNode* node,int val){
        if(node == nullptr){
            return 0;
        }
        val = (val << 1) | node->val;
        if(node->left == nullptr && node->right == nullptr){
            return val;
        }
        return dfs(node->left,val) + dfs(node->right,val);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
};