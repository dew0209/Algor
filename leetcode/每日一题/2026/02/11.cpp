//https://leetcode.cn/problems/longest-balanced-subarray-ii/?envType=daily-question&envId=2026-02-11



const int N = 100010;

typedef long long LL;

struct Node{
    int l,r;
    LL minv = 0,maxv = 0,add = 0;
}tr[N * 4];

class Solution {
public:
    int n;
    vector<int> prefix_sum = vector<int>(N, 0);
    void pushup(Node& root,Node& left,Node& right){
        root.minv = min(left.minv,right.minv);
        root.maxv = max(left.maxv,right.maxv);
    }

    void pushup(int u){
        pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
    }

    void pushdown(int u){
        Node& root = tr[u];
        Node& left = tr[u << 1];
        Node& right = tr[u << 1 | 1];
        if(root.add){
            left.add += root.add;
            left.minv += root.add;
            left.maxv += root.add; 

            right.add += root.add;
            right.minv += root.add;
            right.maxv += root.add; 

            root.add = 0;
        }

    }

    void build(int u,int l,int r){
        if(l == r){
            tr[u] = {l,r,prefix_sum[l - 1],prefix_sum[l - 1]};
        }else {
            tr[u] = {l,r};
            int mid = l + r >> 1;
            build(u << 1,l,mid);
            build(u << 1 | 1,mid + 1,r);
            pushup(u);
        }
    }

    void modify(int u,int l,int r,LL v){
        if(tr[u].l >= l && tr[u].r <= r){
            tr[u].add += v;
            tr[u].maxv += v;
            tr[u].minv += v;
        }else {
            pushdown(u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid)modify(u << 1,l,r,v);
            if(r > mid)modify(u << 1 | 1,l,r,v);
            pushup(u);
        }
    }

    int query(int u,int l,int r,int v){
        
        if (tr[u].r < l || tr[u].l > r) {
            return -1;
        }

        if(tr[u].minv > v || tr[u].maxv < v){
            return -1;
        }
        if(tr[u].l == tr[u].r){
            return tr[u].l;
        }

        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = query(u << 1 | 1,l,r,v);
            if(res != -1){
                return res;
            }

        res = query(u << 1,l,r,v);
            if(res != -1){
                return res;
            }
        return -1;
    }

    int sgn(int u){
        return (u % 2) == 0 ? 1 : -1;
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        map<int, queue<int>> occurrences;
        occurrences[nums[0]].push(1);
        prefix_sum[0] = sgn(nums[0]);
        for(int i = 1;i < n;i++){
            prefix_sum[i] = prefix_sum[i - 1];
            auto& occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefix_sum[i] += sgn(nums[i]);
            }
            occ.push(i + 1);
        }

        build(1,1,n);

        int len = 0;
        for (int i = 1; i <= n; i++) {
            len = max(len, query(1,i + len,n,0) - i + 1);
            auto next_pos = n + 1;
            occurrences[nums[i - 1]].pop();
            if (!occurrences[nums[i - 1]].empty()) {
                next_pos = occurrences[nums[i - 1]].front();
            }
            modify(1,i, next_pos - 1, -sgn(nums[i - 1]));
        }

        return len;
    }
};