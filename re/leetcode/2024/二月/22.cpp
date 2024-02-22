题目链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2024-02-22

思路：递归

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         int n = postorder.size();
        for(int i = 0;i < n;i++){
            cnt[postorder[i]] = i;
        }
        return dfs(preorder,postorder,0,n - 1,0,n - 1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder,int preL,int preR,int posL,int posR){
        if(preL > preR){
            return nullptr;
        }
        int root1 = preL;
        int root2 = cnt[preorder[preL]];

        TreeNode* root = new TreeNode(preorder[preL]);
        int count = 0;
        if(preL < preR){
            count = cnt[preorder[preL + 1]] - posL + 1;
        }        
        root->left = dfs(preorder,postorder,preL + 1,preL + count,posL,posL + count - 1);
        root->right = dfs(preorder,postorder,preL + count + 1,preR,posL + count,posR - 1);

        return root;
    }
};