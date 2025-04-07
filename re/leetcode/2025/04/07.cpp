//dp：https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=daily-question&envId=2025-04-07


class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(auto num : nums){
                sum += num;
            }
            if(sum & 1)return false;
            int target = sum / 2;
            vector<vector<bool>> f(n + 10,vector<bool>(target + 10,false));
            if(nums[0] <= target){
                f[0][nums[0]] = true;
            }
    
            for(int i = 1;i < n;i++){
                for(int j = 0;j < target + 1;j++){
                    f[i][j] = f[i - 1][j];
                    if(j >= nums[i]){
                        f[i][j] = f[i][j] || f[i - 1][j - nums[i]];
                    }
                }
            }
            return f[n - 1][target];
        }
    };