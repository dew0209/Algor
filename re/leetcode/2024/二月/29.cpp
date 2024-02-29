题目链接：https://leetcode.cn/problems/count-number-of-possible-root-nodes/description/?envType=daily-question&envId=2024-02-29

思路：dfs + 换根



const int N = 100010,M = N * 2;

typedef long long LL;

class Solution {
public:
    int idx = 0;
    int e[M],ne[M],h[M];
    unordered_map<LL,LL> cnt;


    void add(int a,int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    LL ha(LL a,LL b){
        LL res = a << 20 | b;
        return res;
    }

    int dfs(int u,int fa){
        int sum = 0;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(j != fa){
                sum += cnt.count(ha(u,j)) + dfs(j,u);
            }
        }
        return sum;
    }

    void dfs_res(int u,int fa,int sum,int& res,int k){
        if(sum >= k){
            res++;
        }
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(j != fa){
                dfs_res(j,u,sum - cnt[ha(u,j)] + cnt[ha(j,u)],res,k);
            }
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size();
        int m = guesses.size();
        memset(h,-1,sizeof h);
        for(int i = 0;i < n;i++){
            add(edges[i][0],edges[i][1]);
            add(edges[i][1],edges[i][0]);
        }       
        for(int i = 0;i < m;i++){
            cnt[ha(guesses[i][0],guesses[i][1])]++;
        }
        int sum = dfs(0,-1);
        int res = 0;
        dfs_res(0,-1,sum,res,k);
        return res;
    }
};