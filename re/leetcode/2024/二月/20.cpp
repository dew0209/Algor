题目链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=daily-question&envId=2024-02-20


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
    map<int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        for(auto c : inorder){
            index[c] = i++;
        }
        return dfs(preorder,inorder,0,preorder.size() - 1,0,inorder.size() - 1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl > pr){
            return nullptr;
        }
        //获得根节点
        int root_index = pl;
        int root_index_i = index[preorder[pl]];

        TreeNode* root = new TreeNode(preorder[root_index]);
        root->left = dfs(preorder,inorder,pl + 1,root_index_i - il + pl,il,root_index_i - 1);
        root->right = dfs(preorder,inorder,root_index_i - il + pl + 1,pr,root_index_i + 1,ir);
        return root;
    }
};