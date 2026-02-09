//https://leetcode.cn/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2026-02-09

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

    vector<int> itemArr;

    void turnArr(TreeNode* node){
        if(node->left){
            turnArr(node->left);
        }
        itemArr.push_back(node->val);
        if(node->right){
            turnArr(node->right);
        }
    }

    TreeNode* dfs(int l,int r){
        int mid = l + r >> 1;
        TreeNode* o = new TreeNode(itemArr[mid]);
        if(l <= mid - 1){
            o->left = dfs(l,mid - 1);
        }
        if(mid + 1 <= r){
            o->right = dfs(mid + 1,r);
        }
        return o;
    }

    TreeNode* balanceBST(TreeNode* root) {
        turnArr(root);
        return dfs(0,itemArr.size() - 1);
    }
};