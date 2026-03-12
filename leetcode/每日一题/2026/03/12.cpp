//https://leetcode.cn/problems/maximize-spanning-tree-stability-with-upgrades/description/?envType=daily-question&envId=2026-03-12

const int N = 100010,M = N ,INF = 0x3f3f3f3f;

struct Edge{
    int a,b,c;
    bool operator< (Edge& w){
        return c > w.c;
    }
}edges[M];

int n = 0,m = 0;
int p[N];
vector<int> needB;
int cnt = 0;

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

void kur(){
    int res = 0;
    sort(edges,edges + m);
    for(int i = 0;i < m;i++){
        int a = edges[i].a,b = edges[i].b;
        a = find(a),b = find(b);
        if(a != b){
            p[a] = b;
            needB.push_back(edges[i].c);
            cnt++;
        }
    }
}

class Solution {
public:
    int maxStability(int t, vector<vector<int>>& edges111, int k) {
        
        m = 0;
        cnt = 0;
        needB.clear();

        n = t;
        for(int i = 1;i <= n;i++)p[i] = i;

        //处理值
        int len = edges111.size();
        int ans = INF;
        for(int i = 0;i < len;i++){
            int u = edges111[i][0];
            int v = edges111[i][1];
            int s = edges111[i][2];
            u++,v++;
            int mus = edges111[i][3];
            if(mus == 1){
                ans = min(ans,s);
                u = find(u),v = find(v);
                cnt++;
                if(u != v){
                    p[u] = v;
                }else {
                    return -1;
                }
            }else {
                edges[m++] = {u,v,s};
            }
        }
        
        kur();
        if(cnt != n - 1){
            return -1;
        }
        int len1 = needB.size();
        if(len1 > 0){
            //非必选边中的最小边权乘以 2。前提条件是 k>0，但实际无需判断，因为 k=0 的时候  ans = min(ans,needB[len1 - 1 - k]); 情况更小。
            ans = min(ans,needB[len1 - 1] * 2);
        }
        if(k < len1){
            ans = min(ans,needB[len1 - 1 - k]);
        }
        return ans;
    }
};