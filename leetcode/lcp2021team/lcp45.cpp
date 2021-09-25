/**
 * 因为可以无限循环(一个环无限的绕)，所以很难控制循环的层数
 *      观察，发现速度每个位置的速度最多为101，所以直接进行所有情况的枚举
 *      设 st[x][y][speed]表示当前(x,y)的速度speed是否有可能
 * 为什么速度最多是101呢?
 *  设点 pos --> h1 -- > h2 -- > h3;
 *  speed(h3) = 1 + h1 - h2 - o2 + h2 - h3 - o3
 *            = 1 + h1 - h3 - o2 - o3
 *      依次类推...
 */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
bool st[110][110][110];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

class Solution {
    vector<vector<int>> map;
    vector<vector<int>> h;
public:
    void dfs(int x,int y,int sp){
        if(st[x][y][sp])return;
        st[x][y][sp] = 1;
        for(int i = 0;i < 4;i++){
            int x1 = dx[i] + x,y1 = dy[i] + y;
            if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
            int v = map[x][y] - map[x1][y1] - h[x1][y1] + sp;
            if(v <= 0)continue;
            if(!st[x1][y1][v])dfs(x1,y1,v);
        }
    }
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
        n = terrain.size();
        m = terrain[0].size();
        memset(st,0,sizeof st);
        map = terrain;
        h = obstacle;
        dfs(position[0],position[1],1);
        vector<vector<int>> res;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(i != position[0] || j != position[1]){
                    if(st[i][j][1])res.push_back({i,j});
                }
            }
        }
        return res;
    }
};