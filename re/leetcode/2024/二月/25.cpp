题目链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/?envType=daily-question&envId=2024-02-25

思路：倍增 + 离散化
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int t1111 = 1;
    map<int,int> cnt;
    int f[100010][16];
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r = bfs(root,q,p);
        return new TreeNode(r);
    }

    int get_v(int v){
        if(cnt.count(v)){
            return cnt[v];
        }
        cnt[v] = t1111++;
        return cnt[v];
    }

    int bfs(TreeNode* root,TreeNode* p1, TreeNode* q1){
        TreeNode* q[100010];
        int deep[100010];
        memset(deep,-1,sizeof deep);
        memset(f,-1,sizeof f);
        int hh = 0,tt = 0;
        q[0] = root;
        deep[get_v(root->val)] = 1;
        while(hh <= tt){
            auto u = q[hh++];
            if(u->left != nullptr){
                q[++tt] = u->left;
                deep[get_v(u->left->val)] = deep[get_v(u->val)] + 1; 
                f[get_v(u->left->val)][0] = u->val;
                for(int i = 1;i <= 15;i++){
                    f[get_v(u->left->val)][i] = f[get_v(f[get_v(u->left->val)][i - 1])][i - 1];
                }
            }
            if(u->right != nullptr){
                q[++tt] = u->right;
                deep[get_v(u->right->val)] = deep[get_v(u->val)] + 1;
                f[get_v(u->right->val)][0] = u->val;
                for(int i = 1;i <= 15;i++){
                    f[get_v(u->right->val)][i] = f[get_v(f[get_v(u->right->val)][i - 1])][i - 1];
                }
            }
        }
        int a = p1->val;
        int b = q1->val;
        if(deep[get_v(a)] < deep[get_v(b)])swap(a,b);
        for(int i = 15;i >= 0;i--){
            if(deep[get_v(f[get_v(a)][i])] >= deep[get_v(b)]){
                a = f[get_v(a)][i];
            }
        }
        if(a == b)return a;
        for(int i = 15;i >= 0;i--){
            if(f[get_v(a)][i] != f[get_v(b)][i]){
                a = f[get_v(a)][i];
                b = f[get_v(b)][i];
            }
        }
        return f[get_v(a)][0];
    }
};