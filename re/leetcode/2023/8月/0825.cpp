题目链接：https://leetcode.cn/problems/count-good-nodes-in-binary-tree/

方法一：深度优先搜索

当前节点的val大于等于整个路径上的最大值，该节点就是一个合法的值

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
    int goodNodes(TreeNode* root) {
        return dfs(root,-0x3f3f3f3f);
    }
    int dfs(TreeNode* r,int v){
        if(!r){
            return 0;
        }
        int res = 0;
        if(r->val >= v){
            v = r->val;
            res++;
        }
        res += dfs(r->left,v) + dfs(r->right,v);
        return res;
    }
};