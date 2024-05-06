// 题目连接：https://leetcode.cn/problems/cherry-pickup/description/
// 思路：动态规划

int f[120][60][60];

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(f,-0x3f,sizeof f);
        f[0][0][0] = (grid[0][0] == 1);
        for(int sum1 = 1;sum1 <= 2 * n - 2;sum1++){
            for(int x1 = 0;x1 <= min(sum1,n - 1);x1++){
                int y1 = sum1 - x1;
                if(y1 < 0 || y1 > n - 1)continue;
                if(grid[x1][y1] == -1)continue;
                for(int x2 = 0;x2 <= min(sum1,n - 1);x2++){
                    int y2 = sum1 - x2;
                    if(y2 < 0 || y2 > n - 1)continue;
                    if(grid[x2][y2] == -1)continue;
                    int& v = f[sum1][x1][x2];
                    if(y1 && y2){
                        v = f[sum1 - 1][x1][x2];
                    }
                    if(x1){
                        v = max(v,f[sum1 - 1][x1 - 1][x2]);
                    }
                    if(x2){
                        v = max(v,f[sum1 - 1][x1][x2 - 1]);
                    }
                    if(x1 && x2){
                        v = max(v,f[sum1 - 1][x1 - 1][x2 - 1]);
                    }
                    v += grid[x1][y1];
                    if(x1 != x2){
                        v += grid[x2][y2];
                    }
                }
            }
        }
        return max(f[2 * n - 2][n - 1][n - 1],0);
    }
};