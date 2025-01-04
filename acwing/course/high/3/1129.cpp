//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2510,M = 13000;

int n,m,S,T;
int h[N],e[M],ne[M],w[M],idx;
bool st[N];
int dist[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

void spfa(){
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
    
}

int main(){
    memset(h,-1,sizeof h);
    cin >> n >> m >> S >> T;
    
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    spfa();
    
    cout << dist[T] << endl;
    
    return 0;
}