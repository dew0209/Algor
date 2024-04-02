题目链接：https://leetcode.cn/problems/all-possible-full-binary-trees/description/?envType=daily-question&envId=2024-04-02


思路：分治

代码：

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
    vector<TreeNode*> res;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(n == 1){
            res = {new TreeNode(0)};
            return res;
        }
        if(n % 2 == 0){
            return res;
        }
        for(int i = 1;i < n;i += 2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - 1 - i);
            for(auto leftTree : left){
                for(auto rightTree : right){
                    res.push_back(new TreeNode(0,leftTree,rightTree));
                }
            }
        }
        return res;
    }
};