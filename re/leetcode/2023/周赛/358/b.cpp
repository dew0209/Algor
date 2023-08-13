题目链接：https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/

方法一：大数乘法

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
    vector<int> mul(vector<int> a,int b){
        int t = 0;
        vector<int> c;
        for(int i = 0;i < a.size() || t;i++){
            if(i < a.size())t += a[i] * b;
            c.push_back(t % 10);
            t /= 10;
        }
        return c;
    }
    ListNode* doubleIt(ListNode* head) {
        //先将每个数拿出来
        vector<int> a;
        while(head != nullptr){
            a.push_back(head->val);
            head = head->next;
        }
        //因为a里面存储的每个位是从高位到低位的，实际上模拟乘法的过程，是从低位开始计算的，为了方便，我们将数组反转
        reverse(a.begin(),a.end());
        auto c = mul(a,2);
        ListNode t,*tail = &t;
        for(int i = c.size() - 1;i >= 0;i--){
            tail->next = new ListNode(c[i]);
            tail = tail->next;
        }
        return t.next;
    }
};