//dfs

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

string g[N];
bool st[N][N];

int n,m;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int dfs(int x,int y){
    
    int s = 1;
    st[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int ax = dx[i] + x;
        int ay = dy[i] + y;
        if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
        if(g[ax][ay] != '.')continue;
        if(st[ax][ay])continue;
        s += dfs(ax,ay);
    }
    
    return s;
}

int main(){
    while(cin >> m >> n,n || m){
        
        memset(st,0,sizeof st);
        
        for(int i = 0;i < n;i++){
            cin >> g[i];
        }
        int x,y;
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(g[i][j] == '@'){
                    g[i][j] = '.';
                    x = i;
                    y = j;
                    break;
                }
            }
            
        }
        
        cout << dfs(x,y) << endl;
    }
    return 0;
}