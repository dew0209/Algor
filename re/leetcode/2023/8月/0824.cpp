题目链接：https://leetcode.cn/problems/count-servers-that-communicate/

方法一：暴力

统计每行每列各有多少个服务器

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> a(n,0);
        vector<int> b(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                a[i] += grid[i][j];
                b[j] += grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    if(a[i] > 1 || b[j] > 1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};