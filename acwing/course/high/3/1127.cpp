//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2510,M = 13000;

int n,m,C;
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
int dist[N];
int p[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int spfa(int S){
    memset(st,0,sizeof st);
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    st[S] = true;
    while(q.size()){
        int u = q.front();
        q.pop();
        st[u] = false;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            int d = dist[u] + w[i];
            if(d < dist[j]){
                dist[j] = d;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
               }
            }
        }
    }
    
    int res = 0;
    
    for(int i = 1;i <= n;i++){
        
        if(dist[i] == 0x3f3f3f3f)return 0x3f3f3f3f;
        res += dist[p[i]];
        
    }
    return res;
    
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n >> m >> C;
    
    for(int i = 1;i <= n;i++){
        cin >> p[i];
    }
    
    for(int i = 0;i < C;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    int res = 0x3f3f3f3f;
    
    for(int i = 1;i <= m;i++){
        res = min(res,spfa(i));
    }
    
    if(res == 0x3f3f3f3f){
        res = -1;
    }
    cout << res << endl;
    return 0;
}