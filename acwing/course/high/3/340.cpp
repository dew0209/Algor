//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010,M = 20010;

typedef pair<int,int> PII;

#define fi first
#define se second

int n,m,k;
int h[N],e[M],ne[M],w[M],idx;
int st[N];
int dist[N];

void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

bool check(int mid){
    
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    dist[1] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        int u = t.se,distance = t.fi;
        if(st[u])continue;
        st[u] = true;
        for(int i = h[u];~i;i = ne[i]){
            int j = e[i];
            int v = distance + (w[i] > mid);
            if(dist[j] > v){
                dist[j] = v;
                q.push({dist[j],j});
            }
        }
    }
    return dist[n] <= k;
}

int main(){
    
    memset(h,-1,sizeof h);
    
    cin >> n >> m >> k;
    
    for(int i = 0;i < m;i++){
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);add(b,a,c);
    }
    
    int l = 0,r = 1e6 + 1;
    
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    if(l == 1e6 + 1)l = -1;
    cout << l << endl;
    return 0;
}