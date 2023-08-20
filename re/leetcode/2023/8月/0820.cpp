题目链接：https://leetcode.cn/problems/root-equals-sum-of-children/description/

方法一：暴力

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
    bool checkTree(TreeNode* root) {
        int v1 = root->val;
        int v2 = root->left->val;
        int v3 = root->right->val;
        return v1 == v2 + v3;
    }
};