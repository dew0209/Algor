
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n,0);
        for(int i = 1;i + 1 < n;i += 2){
            int v = max(max(nums[i - 1],nums[i + 1]) + 1 - nums[i],0);
            pre[i] = v;
            if(i > 1)pre[i] += pre[i - 2];
        }
        if(n % 2){
            return pre[n - 2];
        }
        vector<long long> suf(n,0);
        long long res = pre[n - 3];
        for(int i = n - 2;i - 1 >= 0;i -= 2){
            int v = max(max(nums[i - 1],nums[i + 1]) + 1 - nums[i],0);
            suf[i] = v;
            if(i < n - 2)suf[i] += suf[i + 2];
            res = min(res,suf[i] + (i - 3 >= 0 ? pre[i - 3] : 0));
        }
        return res;
    }
};