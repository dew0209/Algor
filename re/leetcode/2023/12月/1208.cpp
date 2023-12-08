题目链接：https://leetcode.cn/problems/maximum-earnings-from-taxi/description/?envType=daily-question&envId=2023-12-08



const int N = 100010;

class Solution {
public:
    int find(int l,int r,int v,vector<vector<int>>& rides){
        while(l < r){
            int x = l + r + 1 >> 1;
            if(rides[x][1] <= v)l = x;
            else r = x - 1; 
        }
        return l;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        sort(rides.begin(),rides.end(),[&](const vector<int>& w,const vector<int>& r){
            if(w[1] != r[1])return w[1] < r[1];
            return w[0] < r[0];
        });
        vector<vector<int>> road(m + 2);
        road[0] = {0,0,0};
        road[m + 1] = {N,N,N};
        for(int i = 1;i <= m;i++){
            road[i] = rides[i - 1];
        }
        vector<long long> f(m + 2);
        for(int i = 1;i <= m;i++){
            int j = find(0, i,road[i][0],road);
            f[i] = max(f[i - 1],f[j] + road[i][1] - road[i][0] + road[i][2]);
        }
        return f[m];
    }
};