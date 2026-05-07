//https://leetcode.cn/problems/jump-game-ix/description/?envType=daily-question&envId=2026-05-07

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_max(n,0);
        pre_max[0] = nums[0];
        for(int i = 1;i < n;i++){
            pre_max[i] = max(pre_max[i - 1],nums[i]);
        }
        vector<int> ans(n);

        int suf_min = INT_MAX;
        for(int i = n - 1;i >= 0;i--){
            ans[i] = pre_max[i] <= suf_min ? pre_max[i] : ans[i + 1];
            suf_min = min(suf_min,nums[i]);
        }
        return ans;
    }
};