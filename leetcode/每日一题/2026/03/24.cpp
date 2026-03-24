//https://leetcode.cn/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24

const int MOD = 12345;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));

        long long cnt = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res[i][j] = cnt;
                cnt = cnt * grid[i][j] % MOD;
            }
        }
        cnt = 1;
        for(int i = n - 1;i >= 0;i--){
            for(int j = m - 1;j >= 0;j--){
                res[i][j] = res[i][j] * cnt % MOD;
                cnt = cnt * grid[i][j] % MOD;
            }
        }
        return res;
    }
};