//https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/?envType=daily-question&envId=2025-11-26


class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> f(n + 1,vector<vector<int>>(m + 1,vector<int>(k + 1,0)));
        f[0][0][grid[0][0] % k] = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                for(int t = 0;t < k;t++){
                    int x = grid[i][j];
                    int last = ((t - x) % k + k) % k % MOD;
                    if(last >= 0){
                        if(i){
                            f[i][j][t] = (f[i][j][t] + f[i - 1][j][last]) % MOD;
                        }
                        if(j){
                            f[i][j][t] = (f[i][j][t] + f[i][j - 1][last]) % MOD;
                        }
                    }
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};