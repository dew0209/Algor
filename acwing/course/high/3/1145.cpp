//图论

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define fi first
#define se second

const int N = 500,M = N * N / 2;

typedef pair<int,int> PII;

struct Edge{
    int a,b;
    double w;
    bool operator< (Edge& t)const{
        return w < t.w;
    }
}edges[M];

int n,m,k;
PII q[N];
int p[N];

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}

double get_dist(PII a,PII b){
    int x = a.fi - b.fi;
    int y = a.se - b.se;
    return sqrt(x * x + y * y);
}

int main(){
    
    cin >> n >> k;
    
    for(int i = 0;i < n;i++){
        cin >> q[i].fi >> q[i].se;
    }
    
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            edges[m++] = {i,j,get_dist(q[i],q[j])};
        }
    }
    
    sort(edges,edges + m);
    
    for(int i = 0;i < n;i++)p[i] = i;
    
    int cnt = n;
    double res = 0;
    
    for(int i = 0;i < m;i++){
        if(cnt <= k)break;
        int a = edges[i].a;
        int b = edges[i].b;
        double w = edges[i].w;
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){        
            cnt--;
            p[fa] = fb;
            res = w;
        }
    }
    printf("%.2lf\n",res);
    return 0;
}