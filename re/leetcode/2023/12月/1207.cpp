题目链接：https://leetcode.cn/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/?envType=daily-question&envId=2023-12-07


const int N = 50010 * 2;


class Solution {
public:
    int h[N],e[N],ne[N],w[N],idx;
    void add(int a,int b,int c){
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(h,-1,sizeof h);
        for(int i = 0;i < connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            add(a,b,1);
            add(b,a,0);
        }
        return dfs(0,-1);
    }
    int dfs(int u,int fa){
        int s = 0;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(j != fa){
                s += w[i];
                s += dfs(j,u);
            }
        }
        return s;
    }
};