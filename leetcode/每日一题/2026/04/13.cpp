//https://leetcode.cn/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int res = 2e9;
        for(int i = 0;i < n;i++){
            
            if(nums[i] == target){
                res = min(res,abs(i - start));
            }

        }
        return res;
    }
};