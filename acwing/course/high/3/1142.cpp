//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310,M = 8010;

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
    int cnt = 0;
    
    for(int i = 0;i < m;i++){
        
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        
        a = find(a);
        b = find(b);
        
        if(a != b){
            
            p[a] = b;
            cnt++;
            res = w;
        }
    }
    cout << cnt << ' ' << res << endl;
    
    return 0;
}
