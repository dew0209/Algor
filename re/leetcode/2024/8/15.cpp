//题目链接：https://leetcode.cn/problems/maximum-difference-score-in-a-grid/description/?envType=daily-question&envId=2024-08-15

//思路：二维前缀和

class Solution {
public:
    int col[1010];
    int maxScore(vector<vector<int>>& grid) {
        memset(col,0x3f,sizeof col);
        int res = -0x3f3f3f3f;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            int row_min = INT_MAX;
            for(int j = 0;j < m;j++){
                res = max(res, grid[i][j] - min(row_min, col[j]));
                col[j] = min(col[j],grid[i][j]);
                row_min = min(row_min,col[j]);
            }
        }
        return res;
    }
};