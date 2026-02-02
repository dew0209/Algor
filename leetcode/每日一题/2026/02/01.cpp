//https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/?envType=daily-question&envId=2026-02-01


class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        nums[0] = 9999999;
        sort(nums.begin(),nums.end());
        sum += nums[0];
        sum += nums[1];
        return sum;
    }
};