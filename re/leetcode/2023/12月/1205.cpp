题目链接：https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/description/?envType=daily-question&envId=2023-12-05


const int N = 200010;
class Solution {
public:
    int h[N],e[N],ne[N],idx;
    void add(int a,int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       idx = 0;
       memset(h,-1,sizeof h);
       int n = roads.size();
       for(int i = 0;i < n;i++){
           int a = roads[i][0];
           int b = roads[i][1];
           add(a,b);
           add(b,a);
       }
       //耗油量
       long long a = 0;
       dfs(0,-1,a,seats);
       return a;
    }
    long long dfs(int u,int f,long long& a,int seats){
        int s = 1;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(j != f){
                int sum = dfs(j,u,a,seats);
                a += (long long)(sum + seats - 1) / seats;
                s += sum;
            }
        }
        return s;
    }
};