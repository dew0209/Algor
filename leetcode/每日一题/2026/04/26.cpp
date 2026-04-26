//https://leetcode.cn/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool dfs(vector<vector<int>>& st,vector<vector<char>>& grid,int n,int m,int x,int y,int fx,int fy){
        st[x][y] = 1;

        for(int i = 0;i < 4;i++){
        
            int ax = dx[i] + x;
            int ay = dy[i] + y;
            if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
            if(grid[x][y] != grid[ax][ay])continue;
            if(ax == fx && ay == fy)continue;
            if(st[ax][ay])return true;
            if(dfs(st,grid,n,m,ax,ay,x,y)){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> st(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!st[i][j] && dfs(st,grid,n,m,i,j,-1,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};