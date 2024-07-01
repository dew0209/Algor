//题目连接：https://leetcode.cn/problems/maximum-path-quality-of-a-graph/description/?envType=daily-question&envId=2024-07-01
//思路：dfs

const int N = 4010;

int h[N],e[N],ne[N];
int w[N];
int st[N];
int idx;

class Solution {
public:

    void add(int a,int b,int c){
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    void dfs(int u,int time,int value,int& res,int maxTime,vector<int>& values){
        if(u == 0){
            res = max(res,value);
        }
        for(int i = h[u];~i;i = ne[i]){
            if(time + w[i] <= maxTime){
                int j = e[i];
                if(!st[j]){
                    st[j] = true;
                    dfs(j,time + w[i],value + values[j],res,maxTime,values);
                    st[j] = false;
                }else {
                    dfs(j,time + w[i],value,res,maxTime,values);
                }

            }


        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int res = 0;
        idx = 0;
        memset(h,-1,sizeof h);
        int n = edges.size();
        st[0] = true;
        for(int i = 0;i < n;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            add(a,b,c);
            add(b,a,c);
        }
        dfs(0,0,values[0],res,maxTime,values);
        return res;
    }
};