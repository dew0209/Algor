//https://leetcode.cn/problems/xor-after-range-multiplication-queries-i/?envType=daily-question&envId=2026-04-08

const int MOD = 1e9 + 7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        for(int i = 0;i < n;i++){
            for(int j = queries[i][0];j <= queries[i][1];j += queries[i][2]){
                nums[j] = (1LL * nums[j] * queries[i][3]) % (MOD);
            }
        }
        int res = 0;
        for(int i = 0;i < nums.size();i++){
            res = res ^ nums[i];
        }
        return res;
    }
};