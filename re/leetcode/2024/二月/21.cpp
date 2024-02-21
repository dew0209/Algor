题目链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=daily-question&envId=2024-02-21


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0;i < n;i++){
            cnt[inorder[i]] = i;
        }
        return dfs(inorder,postorder,0,n - 1,0, n - 1);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder,int il,int ir,int pl,int pr){
        if(pl > pr)return nullptr;
        int root1 = pr;
        int root2 = cnt[postorder[pr]];
        TreeNode* root = new TreeNode(postorder[pr]);
        root->left = dfs(inorder,postorder,il,root2 - 1,pl,root2 - il + pl - 1);
        root->right = dfs(inorder,postorder,root2 + 1,ir,root2 - il + pl,pr - 1);
        return root;
    }
};