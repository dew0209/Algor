// 题目链接：https://leetcode.cn/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-05-07
// 思路：动态规划

int f[70][70][70];
int dy[] = {-1,0,1};
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(f,-1,sizeof f);
        f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for(int k = 1;k <= n - 1;k++){
            for(int y1 = 0;y1 <= m - 1;y1++){
                for(int y2 = 0;y2 <= m - 1;y2++){
                    int res = -1;
                    for(int a = 0;a < 3;a++){
                        for(int b = 0;b < 3;b++){
                            int ay1 = dy[a] + y1;
                            int by2 = dy[b] + y2;
                            if(ay1 < 0 || ay1 > m - 1 || by2 < 0 || by2 > m - 1 || f[k - 1][ay1][by2] == -1)continue;
                            res = max(res,f[k - 1][ay1][by2]);
                        }
                    }
                    if(res != -1){
                        res += grid[k][y1] + (y1 == y2 ? 0 : grid[k][y2]);
                        f[k][y1][y2] = res;
                    }
                    
                }
            }
        }
        int res = -1;
        for(int i = 0;i <= m - 1;i++){
            for(int j = 0;j <= m - 1;j++){
                res = max(res,f[n - 1][i][j]);
            }
        }
        return res;
    }
};