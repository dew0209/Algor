//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 25010,M = 150010,INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

#define fi first
#define se second

int n,m1,m2,s;
int bcnt;
int h[N],e[M],ne[M],w[M],idx;
int d[N];
int id[N];
int bid[N];
bool st[N];
queue<int> q;
vector<int> block[N];

void add(int a,int b,int c){
    e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}

void dfs(int u,int did){
    
    id[u] = did;
    block[did].push_back(u);
    
    for(int i = h[u];~i;i = ne[i]){
        int j = e[i];
        if(!id[j]){
            dfs(j,did);
        }
    }
}

void dijkstra(int id1){
    
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    
    memset(st,0,sizeof st);
    
    for(int point : block[id1]){
        heap.push({d[point],point});
    }
    
    while(heap.size()){
        
        auto t = heap.top();
        heap.pop();
        int u = t.se,distance = t.fi;
        
        if(st[u])continue;
        st[u] = true;
        
        for(int i = h[u];~i;i = ne[i]){
            
            int j = e[i];
            if(id[j] != id[u]){
                
                bid[id[j]]--;
                if(bid[id[j]] == 0){
                    q.push(id[j]);
                }
                
            }
            if(d[j] > distance + w[i]){
                
                d[j] = distance + w[i];
                if(id[j] == id[u]){
                    
                    heap.push({d[j],j});
                    
                }
                
            }
            
        }
        
    }
    
}

void toopsort(){
    
    memset(d,0x3f,sizeof d);
    
    d[s] = 0;
    
    for(int i = 1;i <= bcnt;i++){
        
        if(!bid[i])q.push(i);
        
    }
    
    
    while(q.size()){
        
        auto t = q.front();
        q.pop();
        dijkstra(t);
        
    }
    
}

int main(){
    
    cin >> n >> m1 >> m2 >> s;
    
    memset(h,-1,sizeof h);
    
    for(int i = 1;i <= m1;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }

    for(int i = 1;i <= n;i++){
        if(!id[i]){
            bcnt++;
            dfs(i,bcnt);
        }
    }
    
    for(int i = 1;i <= m2;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        bid[id[b]]++;
    }
    toopsort();
    
    for(int i = 1;i <= n;i++){
        
        if(d[i] >= INF / 2)cout << "NO PATH" << endl;
        else cout << d[i] << endl;
        
    }
    return 0;
    
}