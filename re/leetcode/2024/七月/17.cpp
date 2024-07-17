//题目连接：https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches/description/?envType=daily-question&envId=2024-07-17

//floyd

class Solution {
public:
    int dist[20][20];
    int st[20];
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;
        for(int state = 0;state < (1 << n);state++){
            //初始化
            for(int i = 0;i < n;i++){
                st[i] = ((state >> i) & 1);
            }
            memset(dist,0x3f,sizeof dist);
            for(int i = 0;i < n;i++)dist[i][i] = 0;
            for(auto road : roads){
                int u = road[0];
                int v = road[1];
                int w = road[2];
                if(st[u] && st[v]){
                    dist[u][v] = min(dist[u][v],w);
                    dist[v][u] = min(dist[v][u],w);
                }
            }
            //floyd
            for(int k = 0;k < n;k++){
                if(st[k]){
                    for(int i = 0;i < n;i++){
                        if(st[i]){
                            for(int j = 0;j < n;j++){
                                if(st[j]){
                                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                                }
                            }
                        }
                    }
                }
            }
            int ok = 1;
            //check
            for(int i = 0;i < n;i++){
                if(st[i]){
                    for(int j = 0;j < n;j++){
                        if(st[j]){
                            if(dist[i][j] > maxDistance){
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
                if(!ok)break;
            }
            res += ok;
        }
        return res;
    }
};