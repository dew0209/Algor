//https://leetcode.cn/problems/maximum-subarray-sum-with-length-divisible-by-k/?envType=daily-question&envId=2025-11-27
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> f(k,LONG_LONG_MAX / 2);
        f[k - 1] = 0;
        long long preSum = 0;
        long long res = LONG_LONG_MIN;
        for(int i = 0;i < n;i++){
            preSum += nums[i];
            res = max(res,preSum - f[i % k]);
            f[i % k] = min(f[i % k],preSum);
        }
        return res;
    }
};