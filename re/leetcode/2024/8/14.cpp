//题目链接：https://leetcode.cn/problems/special-array-ii/description/?envType=daily-question&envId=2024-08-14

//dp

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n,1);
        for(int i = 1;i < n;i++){
            if((nums[i] ^ nums[i - 1]) & 1){
                f[i] = f[i - 1] + 1;
            }
        }
        int m = queries.size();
        vector<bool> res(m,0);
        for(int i = 0;i < m;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(y - x + 1 <= f[y]){
                res[i] = true;
            }
        }
        return res;
    }
};