题目链接：https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/description/?envType=daily-question&envId=2024-02-24

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
    vector<int> arr;    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
       dfs(root); 
       sort(arr.begin(),arr.end());
       for(auto c : arr){
           cout << c << ' ';
       }
       
       cout << endl;
       int n = queries.size();
       int m = arr.size();
       vector<vector<int>> res;
       for(int i = 0;i < n;i++){
           int l = get_l(0,m - 1,queries[i]);
           int r = get_r(0,m - 1,queries[i]);
           res.push_back({l,r});
       }
       return res;
    }

    int get_l(int l,int r,int x){
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(arr[mid] <= x)l = mid;
            else r = mid - 1;
        }
        if(arr[l] <= x)return arr[l];
        return -1;
    }

    int get_r(int l,int r,int x){
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] >= x)r = mid;
            else l = mid + 1;
        }
        if(arr[l] >= x)return arr[l];
        return -1;
    }

    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        arr.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

};