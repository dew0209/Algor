//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n,m;
int st[N][N];
int ans = 0;

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

void dfs(int x,int y,int cnt){
    if(cnt == n * m){
        ans++;
        return ;
    }
    st[x][y] = 1;
    for(int i = 0;i < 8;i++){
        int ax = dx[i] + x;
        int ay = dy[i] + y;
        if(ax < 0 || ax >= n || ay < 0 || ay >= m)continue;
        if(st[ax][ay])continue;
        dfs(ax,ay,cnt + 1);
    }
    st[x][y] = 0;
}

int main(){
    int t;cin >> t;
    while(t--){
        ans = 0;
        memset(st,0,sizeof st);
        int x,y;
        cin >> n >> m >> x >> y;
        dfs(x,y,1);
        cout << ans << endl;
    }
    return 0;
}