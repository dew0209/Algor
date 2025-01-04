//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2510,M = 13000;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
int dist[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void spfa(){
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;
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
    
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n >> m;
    
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    spfa();
    
    int res = 0;
    
    for(int i = 1;i <= n;i++){
        res = max(dist[i],res);
    }
    
    if(res == 0x3f3f3f3f){
        res = -1;
    }
    cout << res << endl;
    return 0;
}