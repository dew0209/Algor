//https://leetcode.cn/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> nums;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if((grid[i][j] - grid[0][0]) % x != 0){
                    return -1;
                }
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        int target = nums[nums.size() / 2];
        int res = 0;

        for(int i = 0;i < nums.size();i++){
            res += abs(target - nums[i]) / x;
        }
        return res;
    }
};