//https://leetcode.cn/problems/multi-source-flood-fill/description/

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    tuple<int,int,int,long long> q[1000000 + 10];
    void bfs(int n,int m,vector<vector<int>>& sources,vector<vector<int>>& res){
        int hh = 0,tt = -1;
        vector<vector<int>> st(n,vector<int>(m,0));
        for(auto& source : sources){
            q[++tt] = {source[0],source[1],source[2],1};
        }
        while(hh <= tt){
            auto& t = q[hh++];
            int x = get<0>(t);
            int y = get<1>(t);
            int color = get<2>(t);
            long long time = get<3>(t);
            

            if(st[x][y] == 0 || (st[x][y] == time && color > res[x][y])){
                //cout << "染色：" << x << " -- " << y << " --- " << color << " --- " << time << endl;
                res[x][y] = color;
                st[x][y] = time;
                for(int i = 0;i < 4;i++){
                    int ax = dx[i] + x;
                    int ay = dy[i] + y;
                    if(ax >= 0 && ax < n && ay >= 0 && ay < m){
                        q[++tt] = {ax,ay,color,1LL * time + 1};
                    }
                }
                
            }
            
        }
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> res(n,vector<int>(m,0));
        bfs(n,m,sources,res);
        return res;
    }
};