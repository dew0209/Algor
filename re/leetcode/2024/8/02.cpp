//https://leetcode.cn/problems/right-triangles/description/?envType=daily-question&envId=2024-08-02


class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> a(n,0);
        vector<int> b(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                a[i] += grid[i][j];
            }
        }

        for(int j = 0;j < m;j++){
            for(int i = 0;i < n;i++){
                b[j] += grid[i][j];
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j]){
                    res = res + (long long)(a[i] - 1) * (b[j] - 1);
                }
            }
        }
        return res;
    }
};