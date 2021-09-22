#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //两个解法使用的循环不一样而已
        /*
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        temp = head;
        int avg = n / k;
        int val = n % k;
        vector<ListNode*> res(k);
        for(int i = 0;i < k && temp != nullptr;i++){
            res[i] = temp;
            int to = avg + (val-- > 0 ? 1 : 0);
            for(int j = 1;j < to;j++){
                temp = temp->next;
            }
            ListNode* p = temp;
            temp = temp->next;
            p->next = nullptr;
        }
        return res;
         */
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp->next;
        }
        int avg = n / k;
        int val = n % k;
        vector<ListNode*> res(k);
        int st = 0;
        temp = head;
        while(st < k && temp != nullptr){
            int total = avg;
            if(val != 0)total++,val--;
            res[st] = temp;
            while(total > 1){
                temp = temp->next;
                total--;
            }
            ListNode* p = temp;
            temp = temp->next;
            p->next = nullptr;
            st++;
        }
        return res;
    }
};