//https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/?envType=daily-question&envId=2026-03-19


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> fx(n + 1,vector<int>(m + 1,0));
        vector<vector<int>> fy(n + 1,vector<int>(m + 1,0));

        int res = 0;

        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                fx[i][j] = fx[i - 1][j] + fx[i][j - 1] - fx[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                fy[i][j] = fy[i - 1][j] + fy[i][j - 1] - fy[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
                if(fx[i][j] > 0 && fx[i][j] == fy[i][j]){
                    res++;
                }
            }
        }
        return res;
    }
};