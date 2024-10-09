//题目链接：https://leetcode.cn/problems/find-subarray-with-bitwise-or-closest-to-k/?envType=daily-question&envId=2024-10-09


//思路：logTrick

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for(int i = 0;i < nums.size();i++){
            int x = nums[i];
            ans = min(ans,abs(k - x));
            for(int j = i - 1;j >= 0 && (nums[j] | x) != nums[j];j--){
                nums[j] |= x;
                ans = min(ans,abs(k - nums[j]));
            }
        }
        return ans;
    }
};