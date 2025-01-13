//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010, M = 10010;

struct Edge{
    int a,b,w;
    bool operator< (Edge &t) const{
        return w < t.w;
    }
}edges[M];

int n,m;
int p[N];

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

int main(){
    int res = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)p[i] = i;
    for(int i = 0;i < m;i++){
        int type,a,b,c;
        cin >> type >> a >> b >> c;
        edges[i] = {a,b,c};
        if(type == 1){
            a = find(a);
            b = find(b);
            p[a] = b;
            res += c;
        }
    }
    
    sort(edges,edges + m);
    
    for(int i = 0;i < m;i++){
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        a = find(a);
        b = find(b);
        if(a != b){
            res += w;
            p[a] = b;
        }
    }
    cout << res << endl;
    return 0;
}