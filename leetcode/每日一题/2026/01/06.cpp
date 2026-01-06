//https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

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
    map<int,int> cnt;
    int maxLevelSum(TreeNode* root) {

        dfs(root,1);
        int res = 0x3f3f3f3f;
        int sum = -0x3f3f3f3f;
        for(auto [x,y] : cnt){
            if(y > sum){
                sum = y;
                res = x;
            }else if(y == sum){
                res = min(res,x);
            }
        }

        return res;
    }

    void dfs(TreeNode* node,int deep){
        cnt[deep] += node->val;

        if(node->left != nullptr){
            dfs(node->left,deep + 1);
        }

        if(node->right != nullptr){
            dfs(node->right,deep + 1);
        }
    }
};