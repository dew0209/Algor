//https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/?envType=daily-question&envId=2026-03-18

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> sum(n + 1,vector(m + 1,0));

        int res = 0;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                int x = grid[i - 1][j - 1];
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;

                if(sum[i][j] <= k){
                    res++;
                }

            }
        }
        return res;
    }
};