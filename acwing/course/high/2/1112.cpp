//dfs

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int ax,ay,bx,by;

string g[N];
int st[N][N];

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

bool dfs(int x,int y){
    st[x][y] = 1;
    if(g[x][y] == '#')return false;
    if(x == bx && y == by){
        return true;
    }
    
    for(int i = 0;i < 4;i++){
        
        int a = dx[i] + x;
        int b = dy[i] + y;
        
        if(a < 0 || a >= n || b < 0 || b >= n)continue;
        
        if(g[a][b] == '#')continue;
        
        if(st[a][b])continue;
        
        if(dfs(a,b))return true;
    }
    
    return false;
}

void solve(){
    
    memset(st,0,sizeof st);
    
    cin >> n;
    
    for(int i = 0;i < n;i++){
        cin >> g[i];
    }
    cin >> ax >> ay >> bx >> by;
    bool fa = dfs(ax,ay);
    
    if(fa){
        cout << "YES" << endl;
    }else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}