//https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
            if(nums[0] < k)return -1;
            int res = nums.size() - 1;
            if(nums[0] != k)res++;
            return res;
        }
};