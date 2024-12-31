//bfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

typedef pair<int,int> PII;

#define fi first
#define se second

int n,m;
string g[N];
int d[N][N];
PII q[N * N];

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

void bfs(){
    
    memset(d,-1,sizeof d);
    
    int hh = 0,tt = -1;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j] == '1'){
                q[++tt] = {i,j};
                d[i][j] = 0;
            }
        }
    }
    
    
    while(hh <= tt){
        auto x = q[hh].fi,y = q[hh].se;
        hh++;
        for(int i = 0;i < 4;i++){
            int ax = dx[i] + x;
            int ay = dy[i] + y;
            if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
            if(d[ax][ay] != -1)continue;
            d[ax][ay] = d[x][y] + 1;
            q[++tt] = {ax,ay};
        }
    }
    
}

int main(){
    
    cin >> n >> m;
    
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    
    bfs();
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}