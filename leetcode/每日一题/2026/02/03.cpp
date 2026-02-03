//https://leetcode.cn/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        while(l + 1 < n && nums[l] < nums[l + 1]){
            l++;
        }
        int r = n - 1;
        while(r - 1 >= 0 && nums[r - 1] < nums[r]){
            r--;
        }
        bool flag = l < r;
        for(int i = l;i < r;i++){
            if(nums[i] <= nums[i + 1]){
                flag = false;
            }
        }

        return l > 0 && r < n - 1 && flag;
    }
};