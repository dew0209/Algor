题目链接：https://leetcode.cn/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-01-03

思路：单调栈


const int N = 100010;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* stk[N];
    int top = -1;
    ListNode* removeNodes(ListNode* head) {
        top = -1;
        while(head != nullptr){
            while(top >= 0 && stk[top]->val < head->val){
                top--;
            }
            if(top >= 0)stk[top]->next=head;
            stk[++top] = head;
            head = head->next;
        }
        if(top == -1)return NULL;
        return stk[0];
    }

};