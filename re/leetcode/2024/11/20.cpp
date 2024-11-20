//题目链接：https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/description/?envType=daily-question&envId=2024-11-20


const int N = 100010;
class Solution {
public:
    int p[N];
    int find(int u){
        if(p[u] != u){
            p[u] = find(p[u]);  
        }
        return p[u];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i = 0;i < n;i++){
            p[i] = i;
        }

        int m = queries.size();
        vector<int> res(m,0);
        int cnt = n - 1;
        for(int i = 0;i < m;i++){
            int l = queries[i][0],r = queries[i][1] - 1;
            int fr = find(r);
            for(int v = find(l);v < fr;v = find(v + 1)){
                p[v] = fr;
                cnt--;
            }
            res[i] = cnt;
        }
        return res;
    }
};