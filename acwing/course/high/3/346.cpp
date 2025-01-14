//图论

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;

struct Edge{
    int a,b,w;
    bool operator< (Edge &t)const{
        return w < t.w;
    }
}edges[N];

int n;
int p[N];
int cnt[N];

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}


void solve(){
    
    cin >> n;
    for(int i = 0;i < n - 1;i++){
        int a,b,c;cin >> a >> b >> c;
        edges[i] = {a,b,c};
    }
    
    for(int i = 1;i <= n;i++){
        p[i] = i;
        cnt[i] = 1;
    }
    
    sort(edges,edges + n - 1);
    
    int res = 0;
    
    for(int i = 0;i < n - 1;i++){
        int a = find(edges[i].a),b = find(edges[i].b),w = edges[i].w;
        if(a != b){
            res += (cnt[a] * cnt[b] - 1) * (w + 1);
            p[a] = b;
            cnt[b] += cnt[a];
        }
    }
    cout << res << endl;
}

int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}