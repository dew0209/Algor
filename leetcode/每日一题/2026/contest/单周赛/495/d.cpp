const int N = 50010;
class Solution {
public:
    int p[N];
    int dist[N];
    int find(int u){
        if(p[u] != u){
            int root = find(p[u]);
            dist[u] ^= dist[p[u]];
            p[u] = root;
        }
        return p[u];
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < N;i++){
            p[i] = i;
        }
        int ans = 0;

        for(auto& e : edges){
            int u = e[0],v = e[1],w = e[2];
            int fu = find(u);
            int fv = find(v);
            if(fu == fv){
                if((dist[u] ^ dist[v]) == w){
                    ans++;
                }
            }else {
                dist[fu] = w ^ dist[u] ^ dist[v];
                p[fu] = fv;
                ans++;
            }
        }
        return ans;

    }
};