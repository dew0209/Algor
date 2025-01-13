//图论

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010,M = N * N,K = 4 * N * N;

struct Edge{
    int a,b,w;
    bool operator< (Edge &t)const{
        return w < t.w;
    }
}edge[K];

int n,m;
int p[M];
int ids[N][N];
int cnt;

int find(int u){
    if(p[u] != u)p[u] = find(p[u]);
    return p[u];
}


void build(){
    
    int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1},dw[] = {1,2,1,2};
    for(int z = 0;z < 2;z++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                for(int u = 0;u < 4;u++){
                    if(u % 2 == z){
                        int ax = i + dx[u];
                        int ay = j + dy[u];
                        
                        if(ax <= 0 || ax > n || ay <= 0 || ay > m)continue;
                        
                        int pa = find(ids[i][j]);
                        int pb = find(ids[ax][ay]);
                        if(pa != pb){
                            edge[cnt++] = {ids[i][j],ids[ax][ay],dw[u]};
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1,t = 1;i <= n;i++){
        for(int j = 1;j <= m;j++,t++){
            ids[i][j] = t;
        }
    }
    for(int i = 1;i <= n * m;i++)p[i] = i;
    int x1,y1,x2,y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        int a = ids[x1][y1];
        int b = ids[x2][y2];
        a = find(a);
        b = find(b);
        p[a] = b;
    }
    build();
    int res = 0;
    for(int i = 0;i < cnt;i++){
        int a = edge[i].a,b = edge[i].b,w = edge[i].w;
        a = find(a);
        b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
        }
    }
    cout << res << endl;
    return 0;
}