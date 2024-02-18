题目链接：https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/?envType=daily-question&envId=2024-02-18



思路：前序遍历

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        dfs(root);
        return res;
    }
    void dfs(Node* root){
        if(root == nullptr)return;
        res.push_back(root->val);
        for(auto r : root->children){
            dfs(r);
        }
    }
};