题目链接：https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/description/?envType=daily-question&envId=2024-03-14


思路：贪心

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long num = nums[n - 1];
        for(int i = n - 2;i >= 0;i--){
            num = nums[i] <= num ? num + nums[i] : nums[i];
        }
        return num;
    }
};