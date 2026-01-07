//https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07


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
    int mod = 1000000007;
    long long ans = 0;
    long long dfs_1(TreeNode* root){
        long long res = 0;

        res = res + root->val;

        if(root->left != nullptr){
            res += dfs_1(root->left);
        }

        if(root->right != nullptr){
            res += dfs_1(root->right);
        }
        return res;
    }

    int maxProduct(TreeNode* root) {
        long long sum = dfs_1(root);
        dfs_2(root,sum);
        //不要在max里面mod，大小会比对不正确
        return (int)(ans % mod);
    }

    long long dfs_2(TreeNode* root,long long sum){

        long long res = 0;

        res += root->val;

        if(root->left != nullptr){
            res += dfs_2(root->left,sum);
        }

        if(root->right != nullptr){
            res += dfs_2(root->right,sum);
        }

        if(res != sum){
            ans = max(ans,1LL * res * (sum - res));
        }

        return res;        

    }

};