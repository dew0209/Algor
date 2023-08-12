题目链接：https://leetcode.cn/problems/merge-k-sorted-lists/description/

[[1,4,5],[1,3,4],[2,6]]


方法一：暴力
1 4 5 
1 3 4
2 6

将每个数单独拿出来放到集合里面，然后排个序，构建一个新的链表
0 <= k <= 10^4
0 <= lists[i].length <= 500

10^4 * 500 = 5 * 10^6

lists[i].length 的总和不超过 10^4

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> a;
        for(int i = 0;i < n;i++){
            ListNode* p = lists[i];
            while(p != nullptr){
                a.push_back(p->val);
                p = p->next;
            }
        }
        sort(a.begin(),a.end());
        ListNode head,*tail = &head;
        for(int i = 0;i < a.size();i++){
            int v = a[i];
            tail->next = new ListNode(v);
            tail = tail->next;
        }
        return head.next;
    }
};



方法二：分治
a1->a2->a3->a4
b1->b2->b3->b4
c1->c2->c3->c4
d1->d2->d3->d4

合并k个不好合并，但是，合并2个是很容易的。

    a  b  c  d
1：a和b合并 c和d合并
2：ab  和 cd进行合并 （ab记为a和b合并之后的结果，cd同理）

class Solution {
public:

    ListNode* mergeTwoList(ListNode* a,ListNode* b){
        if(!a || !b)return a ? a : b;
        ListNode head,*tail = &head,*aptr = a,*bptr = b;
        while(a && b){
            if(a->val < b->val){
                tail->next = a;
                tail = tail->next;
                a = a->next;
            }else {
                tail->next = b;
                tail = tail->next;
                b = b->next;
            }
        }
        tail->next = (a ? a : b);
        return head.next;
    }

    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l == r)return lists[l];
        if(l > r)return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoList(merge(lists,l,mid),merge(lists,mid + 1,r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists,0,lists.size() - 1);
    }
    
};