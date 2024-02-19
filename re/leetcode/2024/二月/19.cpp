题目链接：https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-02-19


思路：后序遍历

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
    vector<int> postorder(Node* root) {
        dfs(root);
        return res;
    }
    void dfs(Node* root){
        if(root == nullptr){
            return;
        }
        for(auto c : root->children){
            dfs(c);
        }
        res.push_back(root->val);
    }
};