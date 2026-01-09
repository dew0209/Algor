//https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09


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
    pair<TreeNode*,int> dfs(TreeNode* root){
        if(!root){
            return {root,0};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        if(l.second > r.second){
            return {l.first,l.second + 1};
        }

        if(l.second < r.second){
            return {r.first,r.second + 1};
        }
        return {root,l.second + 1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};