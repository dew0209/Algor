题目链接：https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/?envType=daily-question&envId=2023-12-06


const int N = 210;

class Solution {
public:
    int h[N],e[N],ne[N],v[N],cnt[N],idx;
    int f[N][2];
    void add(int a,int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        idx = 0;
        memset(h,-1,sizeof h);
        for(int i = 0;i < edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            add(a,b);
            add(b,a);
        }
        for(int i = 0;i < trips.size();i++){
            int s = trips[i][0];
            int t = trips[i][1];
            dfs(s,t,-1);
        }
        for(int i = 0;i < n;i++){
            //重新计算价值
            price[i] = price[i] * cnt[i];
        }
        dfs_res(0,-1,price);
        return min(f[0][1],f[0][0]);
    }
    bool dfs(int s,int t,int f){
        if(s == t){
            cnt[s]++;
            return true;
        }
        for(int i = h[s];~i;i = ne[i]){
            int j = e[i];
            if(j != f && dfs(j,t,s)){
               cnt[s]++;
               return true;
            }
        }
        return false;
    }

    pair<int,int> dfs_res(int u,int fa,vector<int>& price){
        pair<int,int> re = {price[u],price[u] / 2};
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(j != fa){
                auto [x,y] = dfs_res(j,u,price);
                re.first += min(x,y);
                re.second += x;
            }
        }
        f[u][0] = re.first;
        f[u][1] = re.second;
        return re;
    }

};