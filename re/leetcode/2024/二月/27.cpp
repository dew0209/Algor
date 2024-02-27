题目链接：https://leetcode.cn/problems/count-valid-paths-in-a-tree/description/?envType=daily-question&envId=2024-02-27

思路：dfs + 筛法

const int N = 200010;
class Solution {
public:
    int idx = 1;
    int h[N],e[N],ne[N];
    int size[N];
    int primes[N];
    void add(int a,int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    int dfs(int u,int fa){
        if(primes[u])return 0;
        int s = 1;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(!primes[j] && j != fa){
                s += dfs(j,u);
            }
        }
        return s;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        memset(primes,1,sizeof primes);
        memset(h,-1,sizeof h);
        primes[1] = 0;
        for(int i = 2;i <= n;i++){
            if(primes[i]){
                for(int j = i + i;j <= n;j += i){
                    primes[j] = 0;
                }
            }
        }
        for(auto& c : edges){
            int a = c[0];
            int b = c[1];
            add(a,b);
            add(b,a);
        }
        long long res = 0;
        for(int i = 1;i <= n;i++){
            if(primes[i]){
                long long cnt = 0;
                for(int j = h[i];~j;j = ne[j]){
                    int t = e[j];
                    if(primes[t])continue;
                    if(size[t] == 0){
                        size[t] = dfs(t,i);
                    }
                    res += size[t] * cnt;
                    res += size[t];
                    cnt += size[t];
                }
            }

        }
        return res;
    }
};