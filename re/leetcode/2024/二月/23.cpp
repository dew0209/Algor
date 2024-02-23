题目链接：https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-02-23


思路：dfs+排序
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int,long long> cnt;
        dfs(root,1,cnt);
        vector<long long> res;
        for(auto [k,v] : cnt){
            res.push_back(v);
        }
        sort(res.begin(),res.end());
        if(k > res.size())return -1;
        return res[res.size() - k];
    }
    void dfs(TreeNode* root,int deep,map<int,long long>& cnt){
        if(root == nullptr)return;
        cnt[deep] = cnt[deep] + (long long)root->val;
        dfs(root->left,deep + 1,cnt);
        dfs(root->right,deep + 1,cnt);
    }
};