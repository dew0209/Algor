//https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(n,-1);
        f[0] = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(abs(nums[j] - nums[i]) <= target && f[j] != -1){
                    f[i] = max(f[j] + 1,f[i]);
                }
            }
        }
        return f[n - 1];
    }
};