题目链接：https://leetcode.cn/problems/merge-two-binary-trees/description/

方法一：dfs

[1,3,2,5]
[2,1,3,null,4,null,7]


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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
        if(!r1)return r2;
        if(!r2)return r1;
        r1->val = r1->val + r2->val;
        r1->left = mergeTrees(r1->left,r2->left);
        r1->right = mergeTrees(r1->right,r2->right);
        return r1;
    }
};

方法二：bfs

q：存储的是结果集
q1,q2：存储的是下一个要处理的节点的父节点（接下来要处理这个节点的左右子节点）

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;
        TreeNode* head = new TreeNode(root1->val + root2->val);
        queue<TreeNode*> q;//代表结果集
        queue<TreeNode*> q1;//代表root1
        queue<TreeNode*> q2;//代表root2
        q.push(head);
        q1.push(root1);
        q2.push(root2);
        while(q1.size() || q2.size()){
            auto t = q.front();
            auto t1 = q1.front();
            auto t2 = q2.front();
            q.pop();
            q1.pop();
            q2.pop();
            auto l1 = t1->left,l2 = t2->left;
            auto r1 = t1->right,r2 = t2->right;
            if(r1 || r2){
                if(r1 && r2){
                    TreeNode* newT = new TreeNode(r1->val + r2->val);
                    t->right = newT;
                    q.push(newT);
                    q1.push(r1);
                    q2.push(r2);
                }else if(r1){
                    t->right = r1;
                }else if(r2){
                    t->right = r2;
                }
            }
            if(l1 || l2){
                if(l1 && l2){
                    TreeNode* newT = new TreeNode(l1->val + l2->val);
                    t->left = newT;
                    q.push(newT);
                    q1.push(l1);
                    q2.push(l2);
                }else if(l1){
                    t->left = l1;
                }else if(l2){
                    t->left = l2;
                }
            }
        }
        return head;
    }
};
