//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010,M = 200010;

typedef pair<int,int> PII;

#define fi first
#define se second

int n,m,s;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dijkstra(){
    
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    
    priority_queue<PII,vector<PII>,greater<PII>> q;
    
    dist[0] = 0;
    
    q.push({0,0});
    
    while(q.size()){
        
        auto t = q.top();
        q.pop();
        
        int u = t.se,distance = t.fi;
        
        if(st[u])continue;
        st[u] = true;
        for(int i = h[u];~i;i = ne[i]){

            int j = e[i];
            
            int v = distance + w[i];
            
            if(dist[j] > v){
                dist[j] = v;
                q.push({dist[j],j});
            }
        }
    }
    return dist[s];
}

int main(){
    
    while(cin >> n >> m >> s){
        idx = 0;
        
        memset(h,-1,sizeof h);
    
        for(int i = 0;i < m;i++){
            
            int a,b,c;cin >> a >> b >> c;
            add(a,b,c);
            
        }
        int cnt;cin >> cnt;
        for(int i = 0;i < cnt;i++){
            
            int v;cin >> v;
            add(0,v,0);
        }
        
        int res = dijkstra();
        if(res >= 0x3f3f3f3f / 2)res = -1;
        cout << res << endl;
        
    }
    
    
    return 0;
}