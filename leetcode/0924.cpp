
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node* res;
        dfs(res,head);
        return res;
    }
    void dfs(Node* res,Node* node){
        res->next = node;
        res = res->next;
        if(node->child != nullptr)
            dfs(res,node->next);
        if(node->next != nullptr)
            dfs(res,node->next);
        while(res->next != nullptr)res = res->next;
    }
};
