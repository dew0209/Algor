//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int w[N][N];
bool st[N];
int dist[N];

int prim(){
    
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    
    int res = 0;
    
    for(int i = 0;i < n;i++){
        
        int t = -1;
        
        for(int j = 1;j <= n;j++){
            
            if(!st[j] && (t == -1 || dist[t] > dist[j])){
                t = j;
            }
        }
        
        if(dist[t] <= 0x3f3f3f3f / 2){
            res += dist[t];
        }
        st[t] = true;
        for(int j = 1;j <= n;j++){
            
            dist[j] = min(dist[j],w[t][j]);
            
        }
        
    }
    
    return res;
    
}

int main(){
    cin >> n >> m;
    memset(w,0x3f,sizeof w);
    int ans = 0;
    for(int i = 1;i <= m;i++){
        int a,b,c;cin >> a >> b >> c;
        w[a][b] = w[b][a] = c;
        ans += c;
    }
    
    int res = prim();
    cout << ans - res << endl;
    return 0;
}

//此题不适合用prim因为数据给的不是一个图，是多个图


//kruscal

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110,M = 210;

struct Edge{
    
    int a,b,w;
    
    bool operator< (const Edge& c){
        return w < c.w;
    }
}edges[M];

int n,m;
int p[N];

int find(int u){
    
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}


int main(){
    
    cin >> n >> m;
    
    for(int i = 0;i < m;i++){
        
        int a,b,c;cin >> a >> b >> c;
        
        edges[i] = {a,b,c};
        
    }
    
    for(int i = 1;i <= n;i++)p[i] = i;
    
    sort(edges,edges + m);
    
    int res = 0;
    
    for(int i = 0;i < m;i++){
        
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        
        a = find(a);
        b = find(b);
        
        if(a != b)p[a] = b;
        else res += w;
        
    }
    cout << res << endl;
    
    return 0;
}
