// 题目链接：https://leetcode.cn/problems/rotting-oranges/description/?envType=daily-question&envId=2024-05-13

// 思路：bfs

typedef long long LL;
typedef pair<int,int> PII;

const int N = 110;

int hh = 0,tt = -1;
PII q[N];
int cnt[N][N];

int dx[] = {0,-1,0,1},dy[] = {-1,0,1,0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        hh = 0,tt = -1;
        memset(cnt,0,sizeof cnt);
        int n = grid.size();
        int m = grid[0].size();
        int ok = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 2){
                    q[++tt] = {i,j};
                }else if(grid[i][j] == 1){
                    ok++;
                }
            }
        }
        int res = 0;
        if(ok){
            while(hh <= tt){
                auto t = q[hh++];
                int x = t.first;
                int y = t.second;
                for(int i = 0;i < 4;i++){
                    int ax = dx[i] + x;
                    int ay = dy[i] + y;
                    if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
                    if(grid[ax][ay] == 1){
                        grid[ax][ay] = 2;
                        ok--;
                        q[++tt] = {ax,ay};
                        cnt[ax][ay] = cnt[x][y] + 1;
                        res = max(res,cnt[ax][ay]);
                    }
                    
                }
            }
        }
        if(ok){
            return -1;
        }
        return res;
    }
};