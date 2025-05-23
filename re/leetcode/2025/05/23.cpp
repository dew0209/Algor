//https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2025-05-23

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long f0 = 0;//偶数个
        long long f1 = -1e9;//奇数个

        for(int i = 0;i < n;i++){
            long long t = max(f1 + nums[i],f0 + (nums[i] ^ k));
            f0 = max(f0 + nums[i],f1 + (nums[i] ^ k));
            f1 = t;
        }
        return f0;
    }
};