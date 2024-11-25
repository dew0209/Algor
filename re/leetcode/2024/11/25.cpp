//题目链接：https://leetcode.cn/problems/network-delay-time/description/?envType=daily-question&envId=2024-11-25


const int N = 110;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int dist[N][N];
    int st[N];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(dist,0x3f,sizeof dist);
        memset(st,0,sizeof st);

        //init

        for(int i = 1;i <= n;i++){
            dist[i][i] = 0;
        }

        int m = times.size();
        for(int i = 0;i < m;i++){
            int x = times[i][0];
            int y = times[i][1];
            int z = times[i][2];
            dist[x][y] = min(dist[x][y],z);
        }



        int ans = 0;
        for(int i = 0;i < n;i++){
            int t = -1;
            for(int j = 1;j <= n;j++){
                if(!st[j] && (t == -1 || dist[k][t] > dist[k][j])){
                    t = j;
                }
            }

            st[t] = true;

            for(int j = 1;j <= n;j++){
                dist[k][j] = min(dist[k][j],dist[k][t] + dist[t][j]);
            }

            if(dist[k][t] >= INF){
                return -1;
            }

            ans = max(ans,dist[k][t]);
        }
        return ans;
    }
};