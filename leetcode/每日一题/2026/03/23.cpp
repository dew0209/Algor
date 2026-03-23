//https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23


//记忆化搜索
const int INF = 0x3f3f3f3f,MOD = 1e9 + 7;
const int N = 20;
typedef long long LL;
int dx[2] = {0,1},dy[2] = {1,0};
class Solution {
public:
    LL res = -1;
    bool st[N][N];
    LL minv[N][N];
    LL maxv[N][N];
    void dfs(int n,int m,vector<vector<int>>& grid,int x,int y,LL& minv_val,LL& maxv_v){
        if(x == n - 1 && y == m - 1){
            minv_val = maxv_v = grid[x][y];
            minv[x][y] = grid[x][y];
            maxv[x][y] = grid[x][y];
            return ;
        }
        
        if(st[x][y]){
            maxv_v = maxv[x][y];
            minv_val = minv[x][y];
            return;
        }

        minv_val = INF;
        maxv_v = -INF;
        for(int i = 0;i < 2;i++){
            int ax = dx[i] + x;
            int ay = dy[i] + y;

            if(ax < 0 || ax >= n || ay < 0 || ay >= m){
                continue;
            }
            LL iv,xv;
            dfs(n,m,grid,ax,ay,iv,xv);

            LL val1 = grid[x][y] * xv;
            LL val2 = grid[x][y] * iv;
                
            maxv_v = max(maxv_v, max(val1, val2));
            minv_val = min(minv_val, min(val1, val2));
        }
        st[x][y] = true;
        minv[x][y] = minv_val;
        maxv[x][y] = maxv_v;
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        LL max_val, min_val;

        dfs(n,m,grid,0,0,min_val,max_val);
        if (max_val < 0) return -1;
        
        return max_val % MOD;
    }
};


//dp

const int INF = 0x3f3f3f3f,MOD = 1e9 + 7;
const int N = 20;
typedef long long LL;
class Solution {
public:
    LL res = -1;
    bool st[N][N];
    LL minv[N][N];
    LL maxv[N][N];
    

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        memset(minv,0x3f,sizeof minv);
        memset(maxv,-0x3f,sizeof maxv);

        for(int i = 0;i <= n;i++){
            maxv[i][0] = minv[i][0] = 1;
        }
        
        for(int i = 0;i <= m;i++){
            maxv[0][i] = minv[0][i] = 1;
        }

        //开始优化
        maxv[1][1] = minv[1][1] = grid[0][0];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                LL v1 = grid[i - 1][j - 1] * minv[i][j - 1];
                LL v2 = grid[i - 1][j - 1] * maxv[i - 1][j];
                LL v3 = grid[i - 1][j - 1] * maxv[i][j - 1];
                LL v4 = grid[i - 1][j - 1] * minv[i - 1][j];
                if(j - 1 > 0){
                    minv[i][j] = min(min(v1,v3),minv[i][j]);
                    maxv[i][j] = max(max(v1,v3),maxv[i][j]);
                }
                if(i - 1 > 0){
                    minv[i][j] = min(min(v2,v4),minv[i][j]);
                    maxv[i][j] = max(max(v2,v4),maxv[i][j]);
                }
            }
        }

        if(maxv[n][m] < 0)return -1;
        return maxv[n][m] % MOD;
    }
};