//https://leetcode.cn/problems/equal-sum-grid-partition-ii/description/?envType=daily-question&envId=2026-03-26


class Solution {
public:

    vector<vector<int>> rotation(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> re(m,vector<int>(n,0));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                re[j][n - 1 - i] = grid[i][j];
            }
        }
        return re;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        long long sum = 0;
        long long tag = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                total = total + grid[i][j];
            }
        }
        set<long long> exists;
        for(int k = 0;k < 4;k++){
            n = grid.size();
            m = grid[0].size();
            exists.clear();
            exists.insert(0);
            sum = 0;
            if(n < 2){
                grid = rotation(grid);
                continue;
            }
            //只有一列
            if(m == 1){
                for(int i = 0;i < n - 1;i++){
                    sum += grid[i][0];
                    tag = sum * 2 - total;
                    if(tag == 0 || tag == grid[0][0] || tag == grid[i][0]){
                        return true;
                    }
                }
                grid = rotation(grid);
                continue;
            }
            for(int i = 0;i < n - 1;i++){
                for(int j = 0;j < m;j++){
                    exists.insert(grid[i][j]);
                    sum += grid[i][j];
                }
                tag = sum * 2 - total;
                if(i == 0){
                    if(tag == 0 || tag == grid[0][0] || tag == grid[0][m - 1]){
                        return true;
                    }
                }else if(exists.contains(tag)){
                    return true;
                }
            }
            grid = rotation(grid);
        }
        return false;
    }
};