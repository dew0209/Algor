//https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/description/?envType=daily-question&envId=2026-04-27

class Solution {
public:
    bool check(int n,int m,int x,int y,vector<vector<int>>& st){
        
        return x >= 0 && x < n && y >= 0 && y < m && !st[x][y];
    }
    bool dfs(int x,int y,int n,int m,vector<vector<int>>& st,vector<vector<int>>& grid){
        if(x == n - 1 && y == m - 1){
            return true;
        }
        st[x][y] = true;
        int u = grid[x][y];
        int a = 0;
        int b = 0;
        if(u == 1){
            //向左和向右边
            a = x;
            b = y - 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 4 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x;
            b = y + 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 3 || grid[a][b] == 5) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }

        if(u == 2){
            //上和下
            a = x - 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 3 || grid[a][b] == 4) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x + 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 5 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }


        if(u == 3){
            //
            a = x;
            b = y - 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 4 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x + 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 5 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }

        if(u == 4){
            //
            a = x;
            b = y + 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 5 || grid[a][b] == 3) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x + 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 5 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }

        if(u == 5){
            //
            a = x;
            b = y - 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 4 || grid[a][b] == 6) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x - 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 3 || grid[a][b] == 4) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }

        if(u == 6){
            //
            a = x;
            b = y + 1;
            if(check(n,m,a,b,st) && (grid[a][b] == 1 || grid[a][b] == 3 || grid[a][b] == 5) && dfs(a,b,n,m,st,grid)){
                return true;
            }
            //
            a = x - 1;
            b = y;
            if(check(n,m,a,b,st) && (grid[a][b] == 2 || grid[a][b] == 3 || grid[a][b] == 4) && dfs(a,b,n,m,st,grid)){
                return true;
            }
        }
        return false;

    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> st(n,vector<int>(m,0));
        return dfs(0,0,n,m,st,grid);
    }
};