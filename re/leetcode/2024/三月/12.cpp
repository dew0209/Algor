题目链接：https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/description/

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
class FindElements {
public:
    map<int,int> cnt;
    FindElements(TreeNode* root) {
        root->val = 0;
        cnt[0]++;
        dfs(root);
    }

    void dfs(TreeNode* root){
        if(root->left != nullptr){
            root->left->val = root->val * 2 + 1;
            cnt[root->val * 2 + 1]++;
            dfs(root->left);
        }

        if(root->right != nullptr){
            root->right->val = root->val * 2 + 2;
            cnt[root->val * 2 + 2]++;
            dfs(root->right);
        }

    }
    
    bool find(int target) {
        if(cnt.count(target))return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */