#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const int N = 20;

int n,m,k;
char g[N][N];
int cnt[N][N];
int ans = 0;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void dfs(int x,int y,int s){

    if(s == k){
        ans++;
        return;
    }
    cnt[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int ax = dx[i] + x;
        int ay = dy[i] + y;
        if(ax <= 0 || ax > n)continue;
        if(ay <= 0 || ay > m)continue;
        if(g[ax][ay] != '.')continue;
        if(cnt[ax][ay])continue;
        dfs(ax,ay,s + 1);
    }
    cnt[x][y] = 0;
}

int main(){
    
    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> g[i][j];
        }
    }
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(g[i][j] == '.'){
                dfs(i,j,0);
            }
        }
    }
    cout << ans << endl;
}