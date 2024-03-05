题目链接：https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/?envType=daily-question&envId=2024-03-05


思路：dijkstr

#define x first
#define y second

const int N = 100000,MOD = 1e9 + 7;
typedef long long LL;

typedef pair<LL,LL> PII;

class Solution {
public:
    int h[N],e[N],ne[N];
    LL w[N];
    int idx = 0;
    LL dist[N];
    int st[N];
    int cnt[N];
    void add(int a,int b,LL c){
        e[idx] = b;
        ne[idx] = h[a];
        w[idx] = c;
        h[a] = idx++;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        memset(h,-1,sizeof h);
        memset(dist,0x3f,sizeof dist);
        memset(st,0,sizeof st);
        for(auto x : roads){
            add(x[0],x[1],x[2]);
            add(x[1],x[0],x[2]);
        }

        return dijkstr(n);
    }

    int dijkstr(int n){
        dist[0] = 0;
        cnt[0] = 1;
        priority_queue<PII,vector<PII>,greater<PII>> q;
        q.push({dist[0],0});
        while(q.size()){
            auto t = q.top();
            q.pop();
            int u = t.y;LL distance = t.x;
            if(st[u])continue;
            st[u] = true;
            for(int i = h[u];~i;i = ne[i]){
                int j = e[i];
                if(dist[j] > distance + w[i]){
                    dist[j] = distance + w[i];
                    cnt[j] = cnt[u];
                    q.push({dist[j],j});
                }else if(dist[j] == distance + w[i]){
                    cnt[j] = (cnt[j] + cnt[u]) % MOD;
                }
            }
        }
        return cnt[n - 1];
    }
};