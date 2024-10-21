//题目链接：https://leetcode.cn/problems/smallest-range-ii/description/?envType=daily-question&envId=2024-10-21


/*
    思路：贪心
*/

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //针对一个数进行特殊处理
        int res = nums[n - 1] - nums[0];
        for(int i = 1;i < n;i++){
            int mx = max(nums[n - 1] - k,nums[i - 1] + k);
            int mn = min(nums[0] + k,nums[i] - k);
            res = min(res,mx - mn);
        }
        return res;
    }
};