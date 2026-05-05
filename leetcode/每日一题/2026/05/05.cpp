//https://leetcode.cn/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*> ans;
        while(head != nullptr){
            ans.push_back(head);
            head = head->next;
        }

        int n = ans.size();
        
        vector<ListNode*> res(n);
        for(int i = 0;i < n;i++){
            ans[i]->next = nullptr;
            res[(i + k) % n] = ans[i];
        }
        for(int i = 0;i < n - 1;i++){
            res[i]->next = res[i + 1];
        }
         
        return n > 0 ? res[0] : nullptr;
    }
};