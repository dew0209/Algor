//题目链接：https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/



const int N = 50010;
const int MOD = 1e9 + 7;

struct Node{
    int l, r;
    long long t00,t01,t11,t10;
}tr[N * 4];

class Solution {
public:
    void pushup(Node &u,Node &l,Node &r){
        u.t00 = max(0LL,max(l.t01 + r.t00,l.t00 + r.t10));
        u.t01 = max(0LL,max(l.t01 + r.t01,l.t00 + r.t11));
        u.t10 = max(0LL,max(l.t11 + r.t00,l.t10 + r.t10));
        u.t11 = max(0LL,max(l.t10 + r.t11,l.t11 + r.t01));
    }

    void pushup(int u){
        pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
    }

    void build(vector<int> &nums,int u,int l,int r){
        if(l == r){
            tr[u] = {l,r,0,0,max(nums[r - 1],0),0};
        }else {
            tr[u] = {l,r};
            int mid = l + r >> 1;
            build(nums,u << 1,l,mid);
            build(nums,u << 1 | 1,mid + 1,r);
            pushup(u);
        }
    }

    void modify(int u,int x,int v){
        if(tr[u].l == x && tr[u].r == x){
            tr[u].t00 = 0;
            tr[u].t01 = 0;
            tr[u].t10 = 0;
            tr[u].t11 = max(0,v);
        }else {
            int mid = tr[u].l + tr[u].r >> 1;
            if(x <= mid)modify(u << 1,x,v);
            else modify(u << 1 | 1,x,v);
            pushup(u);
        }
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        build(nums,1,1,n);
        int m = queries.size();
        int res = 0;
        for(int i = 0;i < m;i++){
            modify(1,queries[i][0] + 1,queries[i][1]);
            auto ans = tr[1];
            res = ((long long)res + (long long)max(max(ans.t00,ans.t01),max(ans.t10,ans.t11))) % MOD;
        }
        return res;
    }
};