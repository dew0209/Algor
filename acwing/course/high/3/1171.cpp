//图论


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 10010,M = N * 2;

int n,m;
int dist[N];
int st[N];
vector<PII> q[M];
int res[M];
int p[N];

int h[N],e[M],ne[M],w[M],idx;

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int find(int u){
    
    if(p[u] != u)p[u] = find(p[u]);
    
    return p[u];
}

void dfs(int u,int fa){
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(j != fa){
            dist[j] =dist[u] + w[i];
            dfs(j,u);
        }
    }
}

void tarjin(int u){
    
    st[u] = 1;
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(!st[j]){
            tarjin(j);
            p[j] = u;
        }
    }
    
    for(auto item : q[u]){
        
        int y = item.first,id = item.second;
        if(st[y] == 2){
            res[id] = dist[y] + dist[u] - dist[find(y)] * 2;
        }
        
    }
    
    st[u] = 2;
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n >> m;
    
    for(int i = 1;i <= n;i++)p[i] = i;
    
    for(int i = 0;i < n - 1;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        q[a].push_back({b,i});
        q[b].push_back({a,i});
    }
    
    dfs(1,-1);
    
    tarjin(1);
    
    
    for(int i = 0;i < m;i++){
        cout << res[i] << endl;
    }
    return 0;
}