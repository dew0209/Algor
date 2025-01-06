//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 50010,M = 200010;
const int INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

#define fi first
#define se second

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int path[N];
int T[6];
int dist[6][N];
int st[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u,int st){
    
    if(u >= 5)return 0;
    
    int res = INF;
    
    for(int i = 1;i <= 5;i++){
        if(path[i] == true)continue;
        //cout << "从" << T[st] << "到" << T[i] << " : " << dist[st][T[i]] << " -- " << endl;

        path[i] = true;
        res = min(res,dist[st][T[i]] + dfs(u + 1,i));
        path[i] = false;
        //cout << res << endl;
    }
    return res;
}

void dijkstra(int start,int d[]){
    
    memset(st,0,sizeof st);
    memset(d,0x3f,N * 4);
    
    priority_queue<PII,vector<PII>,greater<PII>> q;
    d[start] = 0;
    q.push({0,start});
    
    while(q.size()){
        auto t = q.top();
        q.pop();
        int u = t.se,distance = t.fi;
        if(st[u])continue;
        st[u] = true;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            if(d[j] > distance + w[i]){
                d[j] = distance + w[i];
                q.push({d[j],j});
            }
        }
    }
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n >> m;
    T[0] = 1;
    for(int i = 1;i <= 5;i++){
        cin >> T[i];
    }
    
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    for(int i = 0;i <= 5;i++){
        dijkstra(T[i],dist[i]);
    }
    
    int res = dfs(0,0);
    cout << res << endl;
    return 0;
}