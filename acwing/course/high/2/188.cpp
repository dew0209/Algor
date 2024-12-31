//bfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

#define fi first
#define se second

const int N = 160;

int n,m;
string g[N];
int d[N][N];
PII q[N * N];

int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};

int bfs(){
    
    cin >> m >> n;
    
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    
    int hh = 0,tt = 0;
    
    memset(d,-1,sizeof d);
    
    int a = -1;
    int b = -1;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(g[i][j] == 'K'){
                a = i;
                b = j;
                break;
            }
        }
    }
    
    q[0] = {a,b};
    
    d[a][b] = 0;
    
    while(hh <= tt){
        auto x = q[hh].fi,y = q[hh].se;
        hh++;
        for(int i = 0;i < 8;i++){
            int ax = dx[i] + x;
            int ay = dy[i] + y;
            if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
            if(g[ax][ay] == '*')continue;
            if(d[ax][ay] != -1)continue;
            d[ax][ay] = d[x][y] + 1;
            q[++tt] = {ax,ay};
            if(g[ax][ay] == 'H')return d[ax][ay];
        }
    }
    return -1;
}

int main(){
    
    cout << bfs() << endl;
    return 0;
}