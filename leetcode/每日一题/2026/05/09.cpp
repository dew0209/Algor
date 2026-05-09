//https://leetcode.cn/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ceng = min(m / 2,n / 2);
        for(int start = 0;start < ceng;start++){
            vector<int> r, c, val;
            //左边
            for(int i = start;i < n - start - 1;i++){
                r.push_back(i);
                c.push_back(start);
                val.push_back(grid[i][start]);
            }
            //下边
            for(int i = start;i < m - start - 1;i++){
                r.push_back(n - start - 1);
                c.push_back(i);
                val.push_back(grid[n - start - 1][i]);
            }
            //右
            for(int i = n - 1 - start;i > start;i--){
                r.push_back(i);
                c.push_back(m - 1 - start);
                val.push_back(grid[i][m - 1 - start]);
            }
            //上
            for(int i = m - 1 - start;i > start;i--){
                r.push_back(start);
                c.push_back(i);
                val.push_back(grid[start][i]);
            }
            int total = val.size();
            int kk = k % total;
            for(int i = 0;i < total;i++){
                int idx = (i - kk + total) % total;
                grid[r[i]][c[i]] = val[idx];
            }
        }
        return grid;
    }
};