//https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/description/?envType=daily-question&envId=2024-11-07


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        vector<int> res(n - k + 1,-1);
        for(int i = 0;i < n;i++){
            if(i && nums[i] != nums[i - 1] + 1){
                j = i;
            }
            if(i - j + 1 >= k){
                res[i - k + 1] = nums[i];
            }
        }
        return res;
    }
};