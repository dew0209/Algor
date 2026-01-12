//https://leetcode.cn/problems/maximum-bitwise-and-after-increment-operations/


class Solution {
public:
    int get_len(int u){
        int res = 0;
        while(u){
            u >>= 1;
            res = res + 1;
        }
        return res;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> ops(n,0);
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int bit = get_len(nums[n - 1] + k) - 1;bit >= 0;bit--){
            int target = res | (1 << bit);
            for(int i = 0;i < n;i++){
                int x = nums[i];
                int j = get_len(target & ~x);
                int mask = (1LL << j) - 1;
                ops[i] = (target & mask) - (x & mask);
            }
            sort(ops.begin(),ops.end());
            long long ans = 0;

            for(int i = 0;i < m;i++){
                ans += ops[i];
            }

            if(ans <= k){
                res = target;
            }

        }

        return res;
    }
};