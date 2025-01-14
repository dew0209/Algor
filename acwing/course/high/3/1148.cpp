//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510,M = 20010;

typedef long long LL;

struct Edge{
    
    int a,b,w;
    bool f;
    bool operator< (Edge& t)const{
        return w < t.w;
    }
}edges[M];


int n,m;
int p[N];
int dist1[N][N],dist2[N][N];
int h[N],e[M],ne[M],w[M],idx;

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u,int fa,int dmax1,int dmax2,int d1[],int d2[]){
    d1[u] = dmax1,d2[u] = dmax2;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(j != fa){
            int t1 = d1[u],t2 = d2[u];
            if(w[i] > t1)t2 = dmax2,t1 = w[i];
            else if(w[i] < t1 && w[i] > t2)t2 = w[i];
            dfs(j,u,t1,t2,d1,d2);
        }
        
    }
    
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        edges[i] = {a,b,c};
    }
    
    for(int i = 1;i <= n;i++)p[i] = i;
    
    sort(edges,edges + m);
    LL res = 0;
    for(int i = 0;i < m;i++){
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            p[fa] = fb;
            edges[i].f = true;
            res += (LL)w;
            add(a,b,w);
            add(b,a,w);
        }
    }
    for(int i = 1;i <= n;i++)dfs(i,-1,-1e9,-1e9,dist1[i],dist2[i]);
    LL ans = 1e18;
    for(int i = 0;i < m;i++){
        if(!edges[i].f){
            LL t = 0;
            int a = edges[i].a,b = edges[i].b,w = edges[i].w;
            if(w > dist1[a][b]){
                t = res - dist1[a][b] + w;
            }else if(w > dist2[a][b]){
                t = res - dist2[a][b] + w;
            }
            ans = min(t,ans);
        }
    }
    cout << ans << endl;
    return 0;
}
